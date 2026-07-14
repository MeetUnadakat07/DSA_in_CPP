#include<iostream>
#include<vector>
using namespace std;

// Brute force solution - using only recursion
int waysRec(int n) {                        // O(2^n)
    if(n == 0 || n == 1) {
        return 1;
    }
    return waysRec(n - 1) + waysRec(n - 2);
}

// Optimized solution - using memoization in DP
int waysMemo(int n, vector<int> &dp) {     // O(n)
    if(n == 0 || n == 1) {
        return 1;
    }

    if(dp[n] != -1) {       // already calculated
        return dp[n];
    }
    dp[n] = waysMemo(n - 1, dp) + waysMemo(n - 2, dp);
    return dp[n];
}

// Optimized solution - using tabulation in DP
int waysTab(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 6;
    cout << "ways(" << n << ") = " << waysRec(n) << endl;
    
    vector<int> dpMemo(n + 1, -1);
    cout << "ways(" << n << ") = " << waysMemo(n, dpMemo) << endl;

    cout << "ways(" << n << ") = " << waysTab(n) << endl;
}