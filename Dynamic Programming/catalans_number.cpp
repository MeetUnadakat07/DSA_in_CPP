#include<iostream>
#include<vector>
using namespace std;

int catalanRec(int n) {
    if(n == 0 || n == 1) return 1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += catalanRec(i) * catalanRec(n - i - 1);
    }
    return ans;
}

int catalanMemo(int n, vector<int> &dp) {
    if(n == 0 || n == 1) return 1;
    if(dp[n] != 0) return dp[n];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += catalanMemo(i, dp) * catalanMemo(n - i - 1, dp);
    }
    dp[n] = ans;
    return dp[n];
}

int catalanTab(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

int main() {
    int n = 4;
    cout << catalanRec(n) << endl;
    vector<int> dp(n + 1, 0);
    cout << catalanMemo(n, dp) << endl;
    cout << catalanTab(n) << endl;
}