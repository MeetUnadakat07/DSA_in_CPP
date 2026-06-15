#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Node {
public:
    unordered_map<char, Node *> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie{
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string key) {   // O(L)
        Node *temp = root;

        for(int i = 0; i < key.size(); i++) {
            if(temp -> children.count(key[i]) == 0) {
                temp -> children[key[i]] = new Node();
            }
            temp = temp -> children[key[i]];
        }

        temp -> endOfWord = true;
    }

    bool startsWith(string key) {   // O(L)
        Node *temp = root;

        for(int i = 0; i < key.size(); i++) {
            if(temp -> children[key[i]]) {
                temp = temp -> children[key[i]];
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    Trie trie;

    for(int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }

    string prefix = "app";

    if(trie.startsWith(prefix)) {
        cout << "There exists atleast a string starting with " << prefix << endl;
    } else {
        cout << "There exists no string starting with " << prefix << endl;
    }
}