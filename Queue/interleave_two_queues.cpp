#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &q) {
    queue<int> q2;
    int n = q.size();
    for(int i = 0; i < n / 2; i++) {
        q2.push(q.front());
        q.pop();
    }

    while(!q2.empty()) {
        q.push(q2.front());
        q2.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    for(int i = 1; i <= 10; i++) {
        q.push(i);
    }
    interleave(q);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}