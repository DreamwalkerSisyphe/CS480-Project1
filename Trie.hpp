#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

using namespace std;

class Trie {
public:
    Trie();
    struct Node{
        Node(string _word);
        vector<Node*> letters;
        string word;
        bool end;
    };
    Node* insert(string word);
    Node* search(string word);

private:
    Node* root;
};

#endif