#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack {
    vector<T> vec;
public:
    bool isEmpty() {
        return vec.size() == 0;
    }

    void push(T val) {
        vec.push_back(val);
    }

    void pop() {
        if(isEmpty()) {
            cout << "Stack undeflow. Cannot pop." << endl;
            return;
        }
        vec.pop_back();
    }
    
    T top() {
        // if(isEmpty()) {
        //     cout << "Stack undeflow. Cannot pop." << endl;
        //     return -1;
        // }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }
};

template<class T>
void printStack(Stack<T> s) {
    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    printStack(s);
    s.pop();
    s.pop();
    printStack(s);
}