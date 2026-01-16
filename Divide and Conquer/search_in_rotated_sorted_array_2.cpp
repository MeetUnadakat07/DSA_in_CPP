#include<iostream>
using namespace std;

bool search(int arr[], int target, int st, int end) {
    if(st > end) {
        return false;
    }
    int mid = st + (end - st) / 2;
    if(arr[mid] == target) {
        return true;
    }
    if(arr[st] == arr[mid] && arr[mid] == arr[end]) {
        return search(arr, target, st + 1, end - 1);
    }
    if(arr[st] <= arr[mid]) {
        if(arr[st] <= target && target <= arr[mid]) {
            return search(arr, target, st, mid - 1);
        } else {
            return search(arr, target, mid + 1, end);
        }
    } else {
        if(arr[mid] <= target && target <= arr[end]) {
            return search(arr, target, mid + 1, end);
        } else {
            return search(arr, target, st, mid - 1);
        }
    }
}

int main() {
    // int arr[] = {1, 0, 1, 1, 1};
    int arr[] = {1, 1, 1, 1, 3, 1};
    int n = sizeof(arr) / sizeof(int);
    int target = 3;
    if(search(arr, target, 0, n - 1)) {
        cout << "The element " << target << " is present in the array." << endl;
    } else {
        cout << "The element " << target << " is not present in the array." << endl;
    }
}