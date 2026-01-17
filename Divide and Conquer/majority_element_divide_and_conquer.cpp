#include<iostream>
using namespace std;

int countInRange(int arr[], int st, int end, int num) {
    int count = 0;
    for(int i = st; i <= end; i++) {
        if(arr[i] == num) {
            count++;
        }
    }
    return count;
}

int majorityElement(int arr[], int st, int end) {
    if(st == end) return arr[st];
    int mid = st + (end - st) / 2;

    // Find the majority element in left and right subarray
    int leftMajor = majorityElement(arr, st, mid);
    int rightMajor = majorityElement(arr, mid + 1, end);

    if(leftMajor == rightMajor) return leftMajor;

    // Count how many times does the majority element comes in the subarray 
    int leftCount = countInRange(arr, st, end, leftMajor);
    int rightCount = countInRange(arr, st, end, rightMajor);

    if(leftCount > rightCount) {
        return leftMajor;
    } else {
        return rightMajor;
    }
}

int main() {
    int arr[] = {2, 2, 1, 1, 2, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    int ans = majorityElement(arr, 0, n - 1);
    cout << "The majority element is: " << ans << endl;
}