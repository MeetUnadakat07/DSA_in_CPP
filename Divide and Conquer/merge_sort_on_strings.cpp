#include<iostream>
#include<vector>
using namespace std;

void printArr(string arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(string arr[], int n, int st, int mid, int end) {
    int i = st;
    int j = mid + 1;
    vector<string> str;
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            str.push_back(arr[i]);
            i++;
        } else {
            str.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid) {
        str.push_back(arr[i]);
        i++;
    }
    while(j <= end) {
        str.push_back(arr[j]);
        j++;
    }
    for(int k = 0; k < str.size(); k++) {
        arr[st + k] = str[k];
    }
}

void mergeSort(string arr[], int n, int st, int end) {
    if(st >= end) {
        return;
    }
    int mid = st + (end - st) / 2;
    mergeSort(arr, n, st, mid);
    mergeSort(arr, n, mid + 1, end);
    merge(arr, n, st, mid, end);
}

int main() {
    string arr[]={"sun","earth","mars","mercury"};
    int n = sizeof(arr) / sizeof(string);
    printArr(arr, n);
    mergeSort(arr, n, 0, n - 1);
    printArr(arr, n);
    cout << endl;
}