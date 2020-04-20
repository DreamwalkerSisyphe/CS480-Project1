#include <iostream>
#include <ctime>
#include <string>
#include "Transcript.hpp"

using namespace std;

//Global vars
vector<string> verbs;
vector<string> nouns;
bool safetyMode;

int main(){
    srand(time(NULL)); //Seed RNG

    cout << "Use safety mode (prevents you from using words outside the starting dictionary)? (y/n):";
    char c;
    cinclr();
    cin >> c;
    safetyMode = (c == 'y');
    cout << endl;
    //Get words from files.
    verbs = getWords("verbs.txt");
    nouns = getWords("nouns.txt");

    //Generate a new spell
    pair<string, string> startSpell = makeSpell();

    cout << "Player's starting spell: " << startSpell.first + " " + startSpell.second << endl;

    Transcript* T = new Transcript(startSpell);
    do{
        T->getScenario();
        cout << "Continue? (y/n):";
        cinclr();
        cin >> c;
        cout << endl;
    }while(c == 'y');
    cout << "Describe the ending: ";
    string finale;
    cinclr();
    getline(cin, finale);
    T->setEnding(finale);

    cout << "Transcribed session as " << T->transcribe() << endl;

    exit(0);
}



