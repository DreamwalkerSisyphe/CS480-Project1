#ifndef _GAMETREE_HPP
#define _GAMETREE_HPP

#include "Trie.hpp"
#include "helpers.hpp"

class GameTree {
public:
    GameTree();
    pair<string, string> getBest(string context, int change);

private:
    int eval(string word, string context);
    Trie* verbTrie;
    Trie* nounTrie;
};


#endif //_GAMETREE_HPP
