#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// int trap(vector<int> &heights) {
//     int n = heights.size();
//     if(n < 3) return 0;

//     int total = 0;
    
//     for(int i = 0; i < n; i++) {
//         int lmax = 0, rmax = 0;

//         for(int j = 0; j <= i; j++) {
//             lmax = max(lmax, heights[j]);
//         }
//         for(int j = i; j < n; j++) {
//             rmax = max(rmax, heights[j]);
//         }

//         total += max(0, min(rmax, lmax) - heights[i]);
//     }
//     return total;
// }

// int trap(vector<int> &heights) {
//     int n = heights.size();
//     vector<int> lmax(n);
//     vector<int> rmax(n);

//     lmax[0] = heights[0];
//     rmax[n - 1] = heights[n - 1];

//     for(int i = 1; i < n; i++) {
//         lmax[i] = max(lmax[i - 1], heights[i]);
//     }
//     for(int i = n - 2; i >= 0; i--) {
//         rmax[i] = max(rmax[i + 1], heights[i]);
//     }
    
//     int ans = 0;
//     for(int i = 0; i < n; i++) {
//         ans += max(0, min(lmax[i], rmax[i]) - heights[i]);
//     }
//     return ans;
// }

int trap(vector<int> &heights) {
    int n = heights.size();
    int ans = 0;
    int left = 0, right = n - 1;
    int lmax = 0, rmax = 0;

    while(left < right) {
        lmax = max(lmax, heights[left]);
        rmax = max(rmax, heights[right]);
        
        if(lmax < rmax) {
            ans += lmax - heights[left];
            left++;
        } else {
            ans += rmax - heights[right];
            right--;
        }
    }
    return ans;
}

int main() {
    vector<int> heights = {7, 0, 4, 2, 5, 0, 6, 4, 0, 5};
    int ans = trap(heights);
    cout << "The total water trapped is: " << ans;
}