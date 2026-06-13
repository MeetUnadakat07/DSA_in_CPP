#include<bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freq;

    for(int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }

    sort(nums.begin(), nums.end(), [&](int a, int b) {
        if(freq[a] == freq[b]) {
            return a > b;
        }
        return freq[a] < freq[b];
    });

    return nums;
}

int main() {
    vector<int> nums = {2, 3, 1, 3, 2};
    frequencySort(nums);
    cout << "The frequency sorted array is: ";
    for(int ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
}