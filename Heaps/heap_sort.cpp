#include<iostream> 
#include<vector>
#include<queue>
using namespace std;

void heapify(int i, vector<int> &nums, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxI = i;

    if(left < n && nums[left] > nums[maxI]) {
        maxI = left;
    }
    if(right < n && nums[right] > nums[maxI]) {
        maxI = right;
    }

    if(maxI != i) {
        swap(nums[i], nums[maxI]);
        heapify(maxI, nums, n);
    }
}

void heapSort(vector<int> &nums) {
    int n = nums.size();

    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(i, nums, n);
    }
    for(int i = n - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        heapify(0, nums, i);
    }
}

int main() {
    vector<int> nums = {1, 4, 2, 5, 3};
    heapSort(nums);

    for(int ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
}