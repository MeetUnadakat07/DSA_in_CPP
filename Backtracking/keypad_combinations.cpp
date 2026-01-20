#include<iostream>
#include<vector>
using namespace std;

vector<string> keypad = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void keypadCombintions(string digit, int ele, string ans) {
    if(ele == digit.size()) {
        cout << ans << " ";
        return;
    }
    string letters = keypad[digit[ele] - '0'];

    for(int i = 0; i < letters.size(); i++) {
        keypadCombintions(digit, ele + 1, ans + letters[i]);
    }
    
}

int main() {
    string digit;
    cout << "Enter a keypad combination (in digits): ";
    cin >> digit;
    keypadCombintions(digit, 0, "");
}