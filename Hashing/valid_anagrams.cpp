#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool validAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    unordered_map<char, int> m;
    for(int i = 0; i < s.size(); i++) {
        if(m.count(s[i])) {
            m[s[i]]++;
        } else {
            m[s[i]] = 1;
        }
    }
    for(int i = 0; i < t.size(); i++) {
        if(m.count(t[i])) {
            if(m[t[i]] == 1) {
                m.erase(t[i]);
            } else {
                m[t[i]]--;
            }
        } else {
            return false;
        }
    }
    return m.size() == 0;
}

int main() {
    string str1 = "race";
    string str2 = "care";
    if(validAnagram(str1, str2)) {
        cout << "The string is a valid anagram." << endl;
    } else {
        cout << "The string is not a valid anagram." << endl;
    }
}