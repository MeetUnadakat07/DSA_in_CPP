#include<iostream>
#include<vector>
using namespace std;

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int st, int end) {
    int i = st - 1;
    int pivot = arr[end];
    for(int j = st; j < end; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

void quickSort(int arr[], int st, int end) {
    if(st >= end) {
        return;
    }
    int pivotIdx = partition(arr, st, end);
    quickSort(arr, st, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, end);
}

int main() {
    int arr[] = {6, 3, 7, 5, 2, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << "The array before sorting is: " << endl;
    printArr(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "The array after sorting is: " << endl;
    printArr(arr, n);
}