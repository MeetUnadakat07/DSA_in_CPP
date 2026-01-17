#include<iostream>
#include<vector>
using namespace std;

int merge(int arr[], int st, int mid, int end) {
    int i = st;
    int j = mid + 1;
    int count = 0;
    vector<int> temp;
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            count += (mid - i + 1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = 0; k < temp.size(); k++) {
        arr[st + k] = temp[k];
    }
    return count;
}

int mergeSort(int arr[], int st, int end) {
    if(st == end) {
        return 0;
    }
    int mid = st + (end - st) / 2;
    int left_count = mergeSort(arr, st, mid);
    int right_count = mergeSort(arr, mid + 1, end);
    int merge_count = merge(arr, st, mid, end);
    return left_count + right_count + merge_count;
}

int main() {
    // int arr[] = {2, 4, 1, 3, 5};
    // int arr[] = {2, 3, 4, 5, 6};
    int arr[] = {1, 3, 5, 10, 2, 6, 8, 9};
    int n = sizeof(arr) / sizeof(int);
    int ans = mergeSort(arr, 0, n - 1);
    cout <<"The number of inversions in the array is: " << ans << endl;
}