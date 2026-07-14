#include<iostream>
#include<vector>
using namespace std;

// Brute force solution - using only recursion
int fib(int n) {                        // O(2^n)
    if(n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// Optimized solution - using memoization in DP
int fibMemo(int n, vector<int> &dp) {     // O(n)
    if(n == 0 || n == 1) {
        return n;
    }

    if(dp[n] != -1) {       // already calculated
        return dp[n];
    }
    dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
    return dp[n];
}

// Optimized solution - using tabulation in DP
int fibTab(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 6;
    cout << "fib(" << n << ") = " << fib(n) << endl;
    
    vector<int> dpMemo(n + 1, -1);
    cout << "fib(" << n << ") = " << fibMemo(n, dpMemo) << endl;

    cout << "fib(" << n << ") = " << fibTab(n) << endl;
}