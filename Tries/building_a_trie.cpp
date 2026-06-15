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

    bool search(string key) {   // O(L)
        Node *temp = root;

        for(int i = 0; i < key.size(); i++) {
            if(temp -> children.count(key[i]) == 0) {
                return false;
            }
            temp = temp -> children[key[i]];
        }

        return temp -> endOfWord;
    }
};

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    for(int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }

    string target = "their";

    if(trie.search(target)) {
        cout << "The string exists in the trie." << endl;
    } else {
        cout << "The string does not exist in the trie." << endl;
    }
}