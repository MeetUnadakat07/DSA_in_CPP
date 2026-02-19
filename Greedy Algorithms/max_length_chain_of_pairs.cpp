#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxLength(vector<pair<int, int>> pairs) {
    sort(pairs.begin(), pairs.end(), [](pair<int, int>p1, pair<int, int> p2) {
        return p1.second < p2.second;
    });
    int count = 1;
    int currSec = pairs[0].second;
    for(int i = 1; i < pairs.size(); i++) {
        if(pairs[i].first > currSec) {
            count++;
            currSec = pairs[i].second;
        }
    }
    return count;
}

int main() {
    vector<pair<int, int>> pairs;
    pairs.push_back(make_pair(5, 24));
    pairs.push_back(make_pair(39, 60));
    pairs.push_back(make_pair(5, 28));
    pairs.push_back(make_pair(27, 40));
    pairs.push_back(make_pair(50, 90));

    int maxLen = maxLength(pairs);
    cout << "The maximum length of chain of pairs that can be made is: " << maxLen << endl;
}