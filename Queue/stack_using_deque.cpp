#include<iostream>
#include<deque>
using namespace std;

class Stack {
    deque<int> dq;
public:
    void push(int val) {
        dq.push_front(val);
    }

    void pop() {
        dq.pop_front();
    }

    int top() {
        return dq.front();
    }

    bool empty() {
        return dq.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}