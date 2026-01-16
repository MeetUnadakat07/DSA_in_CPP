#include<iostream>
using namespace std;

int findMin(int arr[], int st, int end) {
    if(st == end) {
        return arr[st];
    }
    int mid = st + (end - st) / 2;
    if(arr[mid] > arr[end]) {
        return findMin(arr, mid + 1, end);
    } else {
        return findMin(arr, st, mid);
    }
}

int main() {
    // int arr[] = {11, 13, 15, 17};
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    int min = findMin(arr, 0, n - 1);
    cout << "The minimum element in the array is: " << min << endl;
}