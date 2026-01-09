#include<iostream>
#include<vector>
using namespace std;

int findFirstOccurance(vector<int> &nums, int target, int i) {
    if (i == nums.size()) return -1;
    if (nums[i] == target) return i;
    return findFirstOccurance(nums, target, i + 1);
}

int findLastOccurance(vector<int> &nums, int target, int i) {
    if(i == -1) return -1;
    if(nums[i] == target)  return i;
    return findLastOccurance(nums, target, i - 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 3, 3, 4};
    int target = 3;
    int fIndex = findFirstOccurance(nums, target, 0);
    int lIndex = findLastOccurance(nums, target, nums.size() - 1);
    if(lIndex == -1 && fIndex == -1) {
        cout << "The number " << target << " is not present in the vector." << endl;
    } else {
        cout << "The number " << target << " is present at index " << fIndex << " for the first time in the vector." << endl;
        cout << "The number " << target << " is present at index " << lIndex << " for the last time in the vector." << endl;
    }
}