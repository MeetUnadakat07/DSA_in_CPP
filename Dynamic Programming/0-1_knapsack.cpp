#include<iostream>
#include<vector>
using namespace std;

// Simple recursion approach
int knapsackRec(vector<int> &val, vector<int> &wt, int w, int n) {  // O(2^n)
    if(w == 0 || n == 0) return 0;

    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];

    // valid weight
    if(itemWt <= w) {
        // include
        int ans1 = knapsackRec(val, wt, w - itemWt, n - 1) + itemVal;
        
        // exclude
        int ans2 = knapsackRec(val, wt, w, n - 1);

        return max(ans1, ans2);
    } else {
        // exclude
        return knapsackRec(val, wt, w, n - 1);
    }
}

// Memoization approach - using DP
int knapsackMemo(vector<int> &val, vector<int> &wt, int w, int n, vector<vector<int>> &dp) {  // O(n*w)
    if(w == 0 || n == 0) return 0;
    
    if(dp[n][w] != -1) {
        return dp[n][w];
    }
    
    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];
    
    // valid weight
    if(itemWt <= w) {
        // include
        int ans1 = knapsackMemo(val, wt, w - itemWt, n - 1, dp) + itemVal;
        
        // exclude
        int ans2 = knapsackMemo(val, wt, w, n - 1, dp);
        
        dp[n][w] =  max(ans1, ans2);
    } else {
        // exclude
        dp[n][w] =  knapsackMemo(val, wt, w, n - 1, dp);
    }
    return dp[n][w];
}

// Tabulation approach - using DP
int knapsackTab(vector<int> &val, vector<int> &wt, int w, int n) {                      // O(n*w)
    vector<vector<int>> dp(n + 1, vector<int> (w + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= w; j++) {
            int itemWt = wt[i - 1];
            int itemVal = val[i - 1];
            
            if(itemWt <= j) {
                dp[i][j] = max(itemVal + dp[i - 1][j - itemWt], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][w];
}

int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;

    cout << "The maximum possible profit that is possible is: " << knapsackRec(val, wt, w, n) << endl;
    
    vector<vector<int>> dp(n + 1, vector<int> (w + 1, -1));
    cout << "The maximum possible profit using memoization that is possible is: " << knapsackMemo(val, wt, w, n, dp) << endl;
    
    cout << "The maximum possible profit using tabulation that is possible is: " << knapsackTab(val, wt, w, n) << endl;
}