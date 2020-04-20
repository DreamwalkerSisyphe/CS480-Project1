#include "Trie.hpp"

Trie::Trie(){
    root = new Node("");
}

Trie::Node::Node(string _word){
    vector<Node*> _letters(26, nullptr);
    letters = _letters;
    word = _word;
    end = false;
}

Trie::Node* Trie::insert(string word) {
    Node* parent = root;
    for(unsigned int i = 0; i < word.size(); i++){
        if(parent->letters[word[i]-'a'] != nullptr)
            parent = parent->letters[word[i]-'a'];
        else{
            Node* next = new Node(word.substr(0, i+1));
            parent->letters[word[i]-'a'] = next;
            parent = next;
        }
    }
    parent->end = true;
    return parent;
}

Trie::Node* Trie::search(string word) {
    Node* parent = root;
    for(unsigned int i = 0; i < word.size(); i++){
        if(parent->letters[word[i]-'a'] != nullptr)
            parent = parent->letters[word[i]-'a'];
        else{
            parent = nullptr;
            break;
        }
    }
    return parent;
}