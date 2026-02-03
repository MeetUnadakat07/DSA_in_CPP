#include<iostream>
#include<stack>
using namespace std;

bool isDuplicate(string str) {
    stack<char> s;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] != ')') {
            s.push(str[i]);
        } else {
            if(s.top() == '(') {
                return true;
            }
            while(s.top() != '(') {
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

int main() {
    string str1 = "((a+b))";
    string str2 = "((a+b)+(c+d))";
    if(isDuplicate(str2)) {
        cout << "The string contains duplicate parenthesis." << endl;
    } else {
        cout << "The string does not contain duplicate parenthesis." << endl;
    }
}