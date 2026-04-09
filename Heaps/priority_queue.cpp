#include<iostream>
#include<queue>
using namespace std;

int main() {
    // priority_queue<int> pq;                          // descending order (uses max heap)
    priority_queue<int, vector<int>, greater<int>> pq;  // ascending order (uses min heap)
    pq.push(5);
    pq.push(10);
    pq.push(3);

    while(!pq.empty()) {
        cout << "Top: " << pq.top() << endl;
        pq.pop();
    }
}