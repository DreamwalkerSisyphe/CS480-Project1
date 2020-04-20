#include "GameTree.hpp"

GameTree::GameTree(){
    extern vector<string> verbs;
    extern vector<string> nouns;
    verbTrie = new Trie();
    nounTrie = new Trie();
    for(string v : verbs)
        verbTrie->insert(v);
    for(string n : nouns)
        nounTrie->insert(n);
};

pair<string, string> getBest(){
    pair<string, string> b; b.first = "create"; b.second = "bear";
    return b;
}

int eval(string word, string context){
    return 1;
}