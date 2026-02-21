#include<iostream>
using namespace std;

int balencedStringSplit(string str) {
    int countL = 0;
    int countR = 0;
    int count = 0;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if(countL == countR) {
            count++;
        }
        if(ch == 'L') {
            countL++;
        } else {
            countR++;
        }
    }
    return count;
}

int main() {
    string str = "RLRRLLRLRL";
    int ans = balencedStringSplit(str);
    cout << "The number of balanced string for splitting is " << ans << endl;
}