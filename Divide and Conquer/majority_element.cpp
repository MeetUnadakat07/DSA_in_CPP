#include<iostream>
using namespace std;

int majorityElement(int nums[], int n) {
    int count = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if(count == 0) {
            ans = nums[i];
        }
        if(nums[i] == ans) {
            count++;
        } else {
            count--;
        }
    }
    return ans;
}

int main() {
    int nums[] ={2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(nums) / sizeof(int);
    cout << "The majority element is: " << majorityElement(nums, n) << endl;
}