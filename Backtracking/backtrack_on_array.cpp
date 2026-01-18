#include<iostream>
using namespace std;

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void changeArr(int arr[], int n, int i) {
    if(i == n) {
        printArr(arr, n);   // Printing the array that is made by recursion
        return;
    }
    arr[i] = i + 1;
    changeArr(arr, n, i + 1);
    // This is the step of backtracking which runs when the recursive functions return the values
    arr[i] -= 2;
}

int main() {
    int arr[5] = {0};
    int n = sizeof(arr) / sizeof(int);
    printArr(arr, n);
    changeArr(arr, n, 0);
    printArr(arr, n);
}