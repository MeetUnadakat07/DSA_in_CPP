#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSubarraysWithSumK(vector<int> &nums, int k) {
    unordered_map<int, int> m;  // sum, count
    m[0] = 1;

    int currSum = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        if(m.count(currSum - k)) {
            count += m[currSum - k];
        }

        if(m.count(currSum)) {
            m[currSum]++;
        } else {
            m[currSum] = 1;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {10, 2, -2, -20, 10};
    int k = -10;

    cout << "The number of subarrays with sum " << k << " is " << countSubarraysWithSumK(nums, k) << endl;
}