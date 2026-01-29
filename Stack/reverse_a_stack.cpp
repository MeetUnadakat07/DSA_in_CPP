#include<bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int> &s, int val) {
    if(s.empty()) {
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);           // while backtracking push the element again to the stack
}

void reverseStack(stack<int> &s) {
    if(s.empty()) return;

    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, temp);
}

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "The original stack is: ";
    printStack(s);
    reverseStack(s);
    cout << "The reversed stack is: ";
    printStack(s);
}