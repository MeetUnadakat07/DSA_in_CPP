#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;
public:
    void push(int data) {
        // move the elements from s1 to s2 
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // Push the data into s1 
        s1.push(data);
        // move the elements from s2 to s1 
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        if(!s1.empty()) {
            s1.pop();
        }
    }

    int front() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}