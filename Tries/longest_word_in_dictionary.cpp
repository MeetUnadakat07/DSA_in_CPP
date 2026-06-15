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

    void longestHelper(Node *root, string &ans, string &temp) {
        for(pair<char, Node *> child : root -> children) {
            if(child.second -> endOfWord) {
                temp.push_back(child.first);
                
                if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }
                
                longestHelper(child.second, ans, temp);
                temp.pop_back();
            }
        }
    }

    string longestStringWithEOW() {
        string ans = "";
        string temp = "";
        longestHelper(root, ans, temp);
        return ans;
    }
};

string longestString(vector<string> dict) {
    Trie trie;
    
    for(int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}

int main() {
    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << "The longest string in the dictionary is: " << longestString(dict) << endl;
}