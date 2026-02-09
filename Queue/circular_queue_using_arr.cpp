#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int capacity, size;
    int f, r;

public:
    Queue(int capacity) {
        this -> capacity = capacity;
        arr = new int(capacity);
        size = 0;
        f = 0;
        r = -1;
    }

    void push(int data) {
        if(size == capacity) {
            cout << "The queue is full." << endl;
            return;
        }
        r = (r + 1) % capacity;
        arr[r] = data;
        size++;
    }

    void pop() {
        if(empty()) {
            cout << "The queue is empty." << endl;
            return;
        }
        f = (f + 1) % capacity;
        size--;
    }

    int front() {
        if(empty()) {
            cout << "The queue is empty." << endl;
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.push(5);
    cout << q.front() << endl;
}