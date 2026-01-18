#include<iostream>
using namespace std;

void findPermutations(string str, string ans) {
    int n = str.size();
    if(n == 0) {
        cout << ans << endl;
        return;
    }
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i + 1, n - i - 1);
        findPermutations(nextStr, ans + ch);
    }
}

int main() {
    string str = "abc";
    findPermutations(str, "");
}