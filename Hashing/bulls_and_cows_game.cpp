#include<bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
    unordered_map<char, int> secretFreq;
    unordered_map<char, int> guessFreq;
    int a = 0, b = 0;       // a -> bulls, b -> cows

    for(int i = 0; i < secret.size(); i++) {
        if(secret[i] == guess[i]) {
            a++;
        } else {
            secretFreq[secret[i]]++;
            guessFreq[guess[i]]++;
        }
    }

    for(auto ele : secretFreq) {
        char digit = ele.first;
        int count = ele.second;

        b += min(count, guessFreq[digit]);
    }

    return to_string(a) + "A" + to_string(b) + "B";
}

int main() {
    string secret = "1807";
    string guess = "7810";

    string ans = getHint(secret, guess);
    cout << ans << endl;
}