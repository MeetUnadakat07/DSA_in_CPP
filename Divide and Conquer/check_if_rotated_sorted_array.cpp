#include<iostream>
using namespace std;

bool check(int arr[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[(i + 1) % n]) {
            count++;
        }
        if(count > 1) return false;
    }
    return true;
}

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    // int arr[] = {2, 1, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    if(check(arr, n)) {
        cout << "The array is a rotated sorted array. " << endl;
    } else {
        cout << "The array is not a rotated sorted array. " << endl;
    }
}