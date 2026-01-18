#include<iostream>
using namespace std;

void findSubsets(string str, string subset) {
    if(str.size() == 0) {
        cout << subset << endl;
        return;
    }
    char ch = str[0];
    findSubsets(str.substr(1, str.size() - 1), subset + ch);    // Yes choice
    findSubsets(str.substr(1, str.size() - 1), subset);         // No choice
}

int main() {
    string str = "abc";
    findSubsets(str, "");
}