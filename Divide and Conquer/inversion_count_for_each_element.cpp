#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, vector<int>& indices, vector<int>& counts, int st, int mid, int end) {
    vector<int> temp;
    int i = st;
    int j = mid + 1;
    int count = 0; 

    while(i <= mid && j <= end) {
        if(nums[indices[j]] < nums[indices[i]]) {
            temp.push_back(indices[j]);
            count++; 
            j++;
        } else {
            counts[indices[i]] += count;
            temp.push_back(indices[i]);
            i++;
        }
    }

    while(i <= mid) {
        counts[indices[i]] += count;
        temp.push_back(indices[i]);
        i++;
    }

    while(j <= end) {
        temp.push_back(indices[j]);
        j++;
    }

    // Copy back to indices
    for(int k = 0; k < temp.size(); k++) {
        indices[st + k] = temp[k];
    }
}

void mergeSort(vector<int>& nums, vector<int>& indices, vector<int>& counts, int st, int end) {
    if(st >= end) return;

    int mid = st + (end - st) / 2;
    mergeSort(nums, indices, counts, st, mid);
    mergeSort(nums, indices, counts, mid + 1, end);
    merge(nums, indices, counts, st, mid, end);
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> counts(n, 0);
    vector<int> indices(n);
    for(int i = 0; i < n; i++) indices[i] = i;

    mergeSort(nums, indices, counts, 0, n - 1);

    return counts;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = countSmaller(nums);

    cout << "Counts of smaller elements after each element: ";
    for(int c : result) {
        cout << c << " ";
    }    
    cout << endl;
}