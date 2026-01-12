#include<iostream>
#include<string>
using namespace std;

int validSubstr(string str) {
    int n = str.length();
    if(n <= 1) {
        return n;
    }

    int count = 0;
    if(str[0] == str[n - 1]) {
        count++;
    }

    count += validSubstr(str.substr(0, n - 1));     // n - 1 chars starting from 0
    count += validSubstr(str.substr(1));            // all the chars starting from 1
    count -= validSubstr(str.substr(1, n - 2));     // n - 2 chars starting from 1

    return count;
}

int main() {
    string str = "abca";
    int count = validSubstr(str);
    cout << count << endl;
}