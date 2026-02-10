#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void firstNonRepeatingChar(string str) {
    vector<int> freq(26, 0);
    queue<char> q;

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);
        
        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if(!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "-1 ";
        }
    }
}

int main(){
    string str = "aabccxb";
    firstNonRepeatingChar(str);
}