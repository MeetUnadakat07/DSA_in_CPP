#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int distinctElements(vector<int> nums) {
    unordered_set<int> s;
    int distEle = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(s.find(nums[i]) == s.end()) {
            s.insert(nums[i]);
            distEle++;
        }
    }
    return distEle;
}

int main() {
    vector<int> nums = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};
    cout << "The number of distinct elements is: " << distinctElements(nums) << endl;
}