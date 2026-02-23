#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int countStudents(vector<int> nums, int maxPages) {
    int student = 1, pages = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(pages + nums[i] <= maxPages) {
            pages += nums[i];
        } else {
            student++;
            pages = nums[i];
        }
    }
    return student;
}

// Linear search
// int maxPages(vector<int> nums, int k) {                 
    //     int low = *max_element(nums.begin(), nums.end());
    //     int high = accumulate(nums.begin(), nums.end(), 0);
    //     for(int i = low; i <= high; i++) {
        //         int currStud = countStudents(nums, i);
        //         if(currStud == k) return i;
        //     }
        //     return -1;
        // }
        
// Binary search
int maxPages(vector<int> nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    
    while(low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(nums, mid);

        if(students > k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {25, 46, 28, 49, 24};
    int k = 4;
    int ans = maxPages(nums, k);
    cout << "The minimum of maximum pages for book allocation is " << ans << endl;
}