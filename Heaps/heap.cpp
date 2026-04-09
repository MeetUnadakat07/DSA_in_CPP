#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Heap {
    vector<int> vec;        // CBT
public:

    void push(int val) {
        // insert
        vec.push_back(val);

        // fix heap
        int childIdx = vec.size() - 1;
        int parIdx = (childIdx - 1) / 2;
        while((parIdx >= 0) && (vec[childIdx] > vec[parIdx])) {
            swap(vec[parIdx], vec[childIdx]);
            childIdx = parIdx;
            parIdx = (childIdx - 1) / 2;
        }
    }

    void heapify(int idx) {
        if(idx >= vec.size()) {
            return;
        }
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;

        int maxIdx = idx;

        if(l < vec.size() && vec[l] > vec[maxIdx]) {
            maxIdx = l;
        }
        if(r < vec.size() && vec[r] > vec[maxIdx]) {
            maxIdx = r;
        }

        swap(vec[idx], vec[maxIdx]);
        if(idx != maxIdx) {
            heapify(maxIdx);
        }
    }

    void pop() {
        swap(vec[0], vec[vec.size() - 1]);

        vec.pop_back();

        heapify(0);
    }

    int top() {
        return vec[0];
    }

    bool empty() {
        return vec.size() == 0;
    }
};

// class Student {
// public:
//     string name;
//     int marks;

//     Student(string name, int marks) {
//         this -> name = name;
//         this -> marks = marks;
//     }

//     bool operator <(const Student &obj) const {
//         return this -> marks < obj.marks; // bhaar aur andar same operator (<) hai to default heap (max) banega
//     }
// };

struct comparePair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;
    }
};

int main() {
    // Heap heap;
    // heap.push(9);
    // heap.push(4);
    // heap.push(8);
    // heap.push(1);
    // heap.push(2);
    // heap.push(5);
    // while(!heap.empty()) {
    //     cout << "top: " << heap.top() << endl;
    //     heap.pop();
    // }

    // priority_queue<Student> pq;
    // pq.push(Student("aman", 85));
    // pq.push(Student("bhumika", 95));
    // pq.push(Student("chetan", 65));
    
    priority_queue<pair<string, int>, vector<pair<string, int>>, comparePair> pq;
    pq.push(make_pair("aman", 85));
    pq.push(make_pair("bhumika", 95));
    pq.push(make_pair("chetan", 65));
    while(!pq.empty()) {
        cout << "top: " << pq.top().first << ": " << pq.top().second << endl;
        pq.pop();
    }
}