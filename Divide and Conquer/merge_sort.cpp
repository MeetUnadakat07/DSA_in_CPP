#include<iostream>
#include<vector>
using namespace std;

void printArr(vector<int> nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void merge(vector<int> &nums, int st, int mid, int end) {
    int i = st;
    int j = mid + 1;
    vector<int> ans;
    while(i <= mid && j <= end) {
        if(nums[i] < nums[j]) {
            ans.push_back(nums[i]);
            i++;
        } else {
            ans.push_back(nums[j]);
            j++;
        }
    }
    while(i <= mid) {
        ans.push_back(nums[i]);
        i++;
    }
    while(j <= end) {
        ans.push_back(nums[j]);
        j++;
    }
    int x = 0;
    for(int i = st; i <= end; i++) {
        nums[i] = ans[x];
        x++;
    }
}

void mergeSort(vector<int> &nums, int st, int end) {
    if(st >= end) {
        return;
    }
    
    int mid = st + (end - st) / 2;
    mergeSort(nums, st, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, st, mid, end);
}

int main() {
    vector<int> nums = {6, 3, 7, 5, 2, 4};
    cout << "The vector before sorting is: " << endl;
    printArr(nums);
    cout << "The vector after sorting is: " << endl;
    mergeSort(nums, 0, nums.size() - 1);
    printArr(nums);
}