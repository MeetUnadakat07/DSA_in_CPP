#include<iostream>
#include<vector>
using namespace std;

int maxActivities(vector<int> st, vector<int> end) {
    int count = 1;                  // A0 is always selected
    int currEnd = end[0];
    cout << "A0 is selected" << endl;
    for(int i = 1; i < end.size(); i++) {
        if(st[i] >= currEnd) {          // non-overlapping
            count++;
            currEnd = end[i];
            cout << "A" << i << " is selected" << endl;
        }
    }
    return count;
}

int main() {
    vector<int> st = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int max = maxActivities(st, end);
    cout << "The maximum number of activities that can be performed is: " << max << endl;
}