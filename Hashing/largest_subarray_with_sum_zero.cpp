#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largestSubWithSumZero(vector<int> &nums) {
    unordered_map<int, int> m;  // sum, idx
    int currSum = 0;
    int maxLen = 0;

    for(int j = 0; j < nums.size(); j++) {
        currSum += nums[j];

        if(currSum == 0) {
            maxLen = j + 1;
        }

        if(m.count(currSum)) {
            int currLen = j - m[currSum];
            maxLen = max(maxLen, currLen);
        } else {
            m[currSum] = j;
        }
    }
    return maxLen;
}

int main() {
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10};
    // vector<int> nums = {1, 0, -4, 3, 1, 0};
    // vector<int> nums = {-31, -48, -90, 54, 20, 95, 6, -86, 22};

    cout << "The largest subarray with sum 0 is of length = " << largestSubWithSumZero(nums) << endl;
}