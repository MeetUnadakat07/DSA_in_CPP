#include<iostream>
#include<stack>
using namespace std;

bool isValid(string str) {
    if(str.size() % 2) return false;        // every bracket should be in pairs

    stack<char> s;
    for(char c : str) {
        if(c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else {
            if(s.empty()) return false;     // closing brackets > opening brackets
            // valid parenthesis 
            if(c == ')' && s.top() == '(') s.pop();
            else if(c == '}' && s.top() == '{') s.pop();
            else if(c == ']' && s.top() == '[') s.pop();
            else return false;
        }
    }
    return s.empty();       // if the stack gets empty then it is valid
}

int main() {
    string str = "([{}]())";
    if(isValid(str)) {
        cout << "It is a valid parenthesis." << endl;
    } else {
        cout << "It is not a valid parenthesis." << endl;
    }
}