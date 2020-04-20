#include "Spell.hpp"

Spell::Spell(pair<string, string> startSpell, pair<string, string> curSpell){
    _startSpell = startSpell;
    _curSpell = curSpell;
    updateLevel();
}

string Spell::getName(){return _curSpell.first + " " + _curSpell.second;}

int Spell::getLevel(){
    updateLevel();
    return _level;
}

void Spell::updateLevel(){
    string start = _startSpell.first + " " + _startSpell.second;
    string cur = getName();
    vector<int> charCountStart(26, 0); vector<int> charCountCur(26, 0);
    for(char c : start){
        char lowc = tolower(c);
        if(lowc >= 'a' && lowc <= 'z')
            charCountStart[lowc - 'a']++;
    }
    for(char c : cur){
        char lowc = tolower(c);
        if(lowc >= 'a' && lowc <= 'z')
            charCountCur[lowc - 'a']++;
    }
    _level = 1;
    for(int i = 0; i < 26; i++){
        _level += abs(charCountStart[i] - charCountCur[i]);
    }
}
