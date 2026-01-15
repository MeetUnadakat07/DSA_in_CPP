#include<iostream>
using namespace std;

int search(int arr[], int target, int st, int end) {
    if(st > end) {
        return -1;
    }
    int mid = st + (end - st) / 2;
    if(arr[mid] == target) {
        return mid;
    }

    if(arr[st] <= arr[mid]) {   // L1
        if(arr[st] <= target && target <= arr[mid]) {         // Left
            return search(arr, target, st, mid - 1);   
        } else {                                    // Right
            return search(arr, target, mid + 1, end);
        }
    } else {                // L2
        if(arr[mid] <= target && target <= arr[end]) {        // Right
            return search(arr, target, mid + 1, end);
        } else {                                    // Left
            return search(arr, target, st, mid - 1);
        }
    }
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    int target = 0;
    int idx = search(arr, target, 0, n - 1);
    cout << "The element " << target << " is found at index " << idx << endl;
}