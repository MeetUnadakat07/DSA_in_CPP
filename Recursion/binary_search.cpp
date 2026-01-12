#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> nums, int target, int st, int end) {
    if(st > end) {
        return -1;
    }
    int mid = (st + end) / 2;
    if(nums[mid] == target) {
        return mid;
    } else if(nums[mid] < target) {
        return binarySearch(nums, target, mid + 1, end);
    } else {
        end = mid - 1;
        return binarySearch(nums, target, st, mid - 1);
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int ele = 3;
    int st = 0;
    int end = nums.size() - 1;
    int idx = binarySearch(nums, ele, st, end);
    cout << "The element is found at index " << idx << endl;
}