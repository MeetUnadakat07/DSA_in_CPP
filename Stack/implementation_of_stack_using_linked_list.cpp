#include<iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node *next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

template <class T>
class Stack {
    Node<T> *head;

public: 
    Stack() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(T val) {
        Node<T> *newNode = new Node<T>(val);
        if(!head) {
            head = newNode;
        } else {
            newNode -> next = head;
            head = newNode;
        }
    }

    void pop() {
        if(!head) {
            cout << "Stack underflow. Cannot pop." << endl;
            return;
        }
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
    }

    T top() {
        return head -> data;
    }
};

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    s.pop();
    s.pop();
}