#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> majorityElement(vector<int> &nums) {
    unordered_map<int, int> m;
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++) {
        if(m.count(nums[i])) {
            m[nums[i]]++;
        } else {
            m[nums[i]] = 1;
        }
    }
    
    for(pair<int, int> p : m) {
        if(p.second > (nums.size() / 3)) {
            ans.push_back(p.first);
        }
    }
    return ans;
}

int main() {
    // vector<int> nums = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    vector<int> nums = {1, 2};

    vector<int> ans = majorityElement(nums);
    cout << "The majority element is: ";
    for(int ele : ans) {
        cout << ele << " ";
    }
    cout << endl;
}