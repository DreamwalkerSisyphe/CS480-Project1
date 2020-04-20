#include "Transcript.hpp"

Transcript::Transcript(pair<string, string> _startSpell) : startSpell{_startSpell} {}

void Transcript::getScenario() {
    string scenarioText;
    cout << "Enter the scenario text: ";
    cinclr();
    getline(std::cin, scenarioText);

    string currentVerb;
    string currentNoun;
    bool valid = true;
    extern bool safetyMode;
    do {
        if(!valid)
            cout << "Spell uses words not in dictionary." << endl;
        cout << "Enter a new spell: ";
        cinclr();
        cin >> currentVerb;
        cin >> currentNoun;
        if(safetyMode)
            valid = inDict(currentVerb, currentNoun);
    }while(!valid);
    pair<string, string> newSpell;
    newSpell.first = currentVerb;
    newSpell.second = currentNoun;
    Spell *currentSpell = new Spell(startSpell, newSpell);

    cout << "New spell level: " << currentSpell->getLevel() << endl;

    vector <int> diceRolls;
    //dice rolls
    for(int i = 0 ; i < 6; i++)
        diceRolls.push_back((rand()%6)+1);

    int successfulRolls = 0;
    for(int i : diceRolls) {
        if (i >= 4) {
            if (i == 6) //exploding die
                diceRolls.push_back((rand() % 6) + 1); //roll an extra dice
            successfulRolls++;
        }
    }
    bool successfulSpell = successfulRolls >= currentSpell->getLevel();

    cout << "Dice: " << successfulRolls << " successful dice rolls. ";
    cout<< (successfulSpell ? "Spell successfully cast." : "Spell failed to cast.") << endl;

    int successRating;
    cout << "Success rating: ";
    cinclr();
    cin >> successRating;

    Scenario *s = new Scenario(scenarioText, currentSpell, successfulSpell, (signed char)successRating);

    allScenarios.push_back(s);
}

void Transcript::setEnding(string _ending) {ending = _ending;}

string Transcript::transcribe(){
    char r = 30;
    char u = 31;
    char g = 29;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int month = 1 + ltm->tm_mon; int day = ltm->tm_mday; int year = 1900 + ltm->tm_year;
    int hour = ltm->tm_hour; int minute = ltm->tm_min; int second = ltm->tm_sec;

    string filename = (month < 10 ? "0" : "") + to_string(month) + '-' + (day < 10 ? "0" : "") + to_string(day) + '-' + to_string(year) + '('
            + (hour < 10 ? "0" : "") + to_string(hour) + ';' + (minute < 10 ? "0" : "") + to_string(minute) + ';' + (second < 10 ? "0" : "") + to_string(second)
            + ").gts"; //Date and time.gts (Game Transcript) file extension
    ofstream script("transcripts/" + filename);

    script << startSpell.first + " " + startSpell.second;
    for(Scenario *s : allScenarios){
        script << r;
        script << s->_text << u;
        script << s->_spell->getName() << u;
        char c = 112; //First four filler bits
        c |= (s->_success ? 8 : 0); //Fifth bit representing success
        c |= ((int)s->_rating) + 2; //Last three bits representing the rating
        script << c;
    }

    script << g;
    script << ending;

    script.close();

    return filename;
}
