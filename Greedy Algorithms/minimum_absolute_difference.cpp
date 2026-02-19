#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumAbsoluteDifference(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int diff = 0;
    for(int i = 0; i < a.size(); i++) {
        diff += abs(a[i] - b[i]);
    }
    return diff;
}

int main() {
    vector<int> a = {4, 1, 8, 7};
    vector<int> b = {2, 3, 6, 5};
    int diff = minimumAbsoluteDifference(a, b);
    cout << "The minimum absolute difference possible is: " << diff << endl;
}