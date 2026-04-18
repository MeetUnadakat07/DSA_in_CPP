#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++) {
        int comp = target - nums[i];
        if(m.count(comp)) {
            return {m[comp], i};
        }
        m[nums[i]] = i;
    }
    return {-1};
}

int main() {
    vector<int> nums = {1, 2, 7, 11, 15, 5, 9};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    } 
    cout << endl;
}