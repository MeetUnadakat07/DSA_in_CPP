#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void printUnion(vector<int> nums1, vector<int> nums2) {
    unordered_set<int> s;

    for(int ele : nums1) {
        s.insert(ele);
    }
    for(int ele : nums2) {
        s.insert(ele);
    }

    for(int ele : s) {
        cout << ele << " ";
    }
    cout << endl;
}

void printIntersection(vector<int> nums1, vector<int> nums2) {
    unordered_set<int> s;
    for(int ele : nums1) {
        s.insert(ele);
    }

    for(int ele : nums2) {
        if(s.find(ele) != s.end()) {
            cout << ele << " ";
            s.erase(ele);
        }
    }
}

int main() {
    vector<int> nums1 = {7, 3, 9};
    vector<int> nums2 = {6, 3, 9, 2, 9, 4};

    cout << "Union: ";
    printUnion(nums1, nums2);
    cout << "Intersection: ";
    printIntersection(nums1, nums2);
}