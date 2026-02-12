#include<bits/stdc++.h>
using namespace std;

// vector<int> maxSlidingWindow(vector<int> &nums, int k) {
//     int n = nums.size();
//     vector<int> ans;
//     for(int i = 0; i <= n - k; i++) {
//         int maximum = INT_MIN;
//         for(int j = i; j < i + k; j++) {
//             maximum = max(maximum, nums[j]);
//         }
//         ans.push_back(maximum);
//     }
//     return ans;
// }

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    deque<int> dq;

    int left = 0;
    for(int right = 0; right < nums.size(); right++) {

        // Agar koi value choti hai right wale se to usko dq ke rear se remove karo 
        while(dq.size() != 0 && nums[dq.back()] <= nums[right]) {
            dq.pop_back();
        }

        // Out of window elements ko dq se remove karna hai 
        if(right >= k && dq.size() != 0 && dq.front() == left) {
            dq.pop_front();
        }

        // Include the right index in the window always 
        dq.push_back(right);

        if(right >= k) left++;
        // Push to the result vector if we have filled the window 
        if(right >= k - 1) {
            int max = nums[dq.front()];
            result.push_back(max);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {20, 40, 70, 30, 60, 40, 10, 30, 80};
    int k = 4;
    
    vector<int> ans = maxSlidingWindow(nums, k);
    for(int ele : ans) {
        cout << ele << " ";
    } 
    cout << endl;
}