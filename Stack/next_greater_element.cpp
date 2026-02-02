#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreater(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;
    for(int i = n - 1; i >= 0; i--) {       // run backwards loop
        int curr = nums[i];
        while(!s.empty() && s.top() <= curr) {      // pop until we find next greater
            s.pop();
        }
        if(!s.empty()) {
            ans[i] = s.top();       // found the next greater
        } 
        s.push(curr);
    }
    return ans;
}

int main() {
    vector<int> nums = {6, 8, 0, 1, 3};
    vector<int> ans = nextGreater(nums);
    for(int ele : ans) {
        cout << ele << " ";
    }
    cout << endl;
}