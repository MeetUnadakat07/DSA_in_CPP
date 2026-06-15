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

bool helper(Trie &trie, string key) {
    if(key.size() == 0) return true;

    for(int i = 0; i < key.size(); i++) {
        string first = key.substr(0, i + 1);    // from 0 of size i + 1
        string second = key.substr(i + 1);      // from i + 1 to end

        // agar first exist karta hai to hi second ke liye call lagaao aur agar dono true hai to return true
        if(trie.search(first) && helper(trie, second)) {
            return true;
        }
    }
    // ek bhi nhi ban raha
    return false;
}

bool wordBreak(vector<string> dict, string key) {
    Trie trie;
    for(int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }
    
    return helper(trie, key);
}

int main() {
    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    string key = "ilikesamsung";
    if(wordBreak(dict, key)) {
        cout << "The word break is possible." << endl;
    } else {
        cout << "The word break is not possible." << endl;
    }
}