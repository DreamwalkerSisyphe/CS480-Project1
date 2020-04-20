#include "helpers.hpp"

void cinclr(){
    while (cin.get() == '\n'); //Clear excessive newlines.
    cin.unget();
}

void clean(string& s){
    if(s[s.size()-1] == '\r' || s[s.size()-1] == '\n') //Thank linux for making this even necessary
        s.pop_back();
    s.erase( std::remove_if( s.begin(), s.end(), []( char c ) { return !std::isalpha(c) ; } ), s.end() ); //Get rid of non-letters
    transform(s.begin(), s.end(), s.begin(), ::tolower); //lowercase
}

vector<string> getWords(string filename){
    ifstream file(filename);
    vector<string> words;
    string word;
    while(!file.eof()){
        file >> word;
        clean(word);
        words.push_back(word);
    }
    file.close();
    return words;
}

pair<string, string> makeSpell(){
    extern vector<string> verbs;
    extern vector<string> nouns;
    pair<string, string> spellPair;
    spellPair.first = verbs[rand() % verbs.size()];
    spellPair.second = nouns[rand() % nouns.size()];
    return spellPair;
}

bool inDict(string verb, string noun){
    extern vector<string> verbs;
    extern vector<string> nouns;
    return (find(verbs.begin(), verbs.end(), verb) != verbs.end()) && (find(nouns.begin(), nouns.end(), noun) != nouns.end());
}