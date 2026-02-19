#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double maximumValue(vector<int> value, vector<int> weight, int capacity) {
    int n = value.size();
    vector<pair<double, int>> ratio(n, make_pair(0.0, 0));

    for(int i = 0; i < n; i++) {
        double r = value[i] / (double)weight[i];
        ratio[i] = make_pair(r, i);
    }
    sort(ratio.begin(), ratio.end(), [](pair<double, int> p1, pair<double, int> p2) {
        return p1.first > p2.first;
    });
    double ans = 0;
    for(int i = 0; i < n; i++) {
        int idx = ratio[i].second;
        if(weight[idx] < capacity) {
            ans += value[idx];
            capacity -= weight[idx];
        } else {
            ans += ratio[i].first * capacity;
            capacity = 0;
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;
    double ans = maximumValue(value, weight, capacity);
    cout << "The maximum value is: " << ans << endl;
}