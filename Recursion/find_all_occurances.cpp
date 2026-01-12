#include<iostream>
#include<vector>
using namespace std;

vector<int> findAllOccurances(vector<int> &arr, int target, int i, vector<int> &ans) {
    if(i == arr.size()) return ans;
    if(arr[i] == target) {
        ans.push_back(i);
    }
    return findAllOccurances(arr, target, i + 1, ans);
}

int main() {
    vector<int> arr = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int target = 2;
    cout << "The indices at which " << target << " is present are: ";
    vector<int> ans;
    findAllOccurances(arr, target, 0, ans);
    for(int ele : ans) {
        cout << ele << " ";
    }
}