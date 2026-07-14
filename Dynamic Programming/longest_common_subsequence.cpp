#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lcsRec(string s1, string s2, int n, int m) {
    if(n < 0 || m < 0) return 0;

    if(s1[n] == s2[m]) {
        return 1 + lcsRec(s1, s2, n - 1, m - 1);
    } else {
        return max(lcsRec(s1, s2, n - 1, m), lcsRec(s1, s2, n, m - 1));
    }
}

int lcsMem(string s1, string s2, vector<vector<int>> &dp, int n, int m) {
    if(n < 0 || m < 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n] == s2[m]) {
        dp[n][m] = 1 + lcsMem(s1, s2, dp, n - 1, m - 1);
    } else {
        dp[n][m] = max(lcsMem(s1, s2, dp, n - 1, m), lcsMem(s1, s2, dp, n, m - 1));
    }
    return dp[n][m];
}

int lcsTab(string s1, string s2, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string s1 = "abcdge";
    string s2 = "abedg";
    int n = s1.size();
    int m = s2.size();

    cout << "The length of the LCS is: " << lcsRec(s1, s2, n - 1, m - 1) << endl;
    
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    cout << "The length of the LCS (memo) is: " << lcsMem(s1, s2, dp, n - 1, m - 1) << endl;

    cout << "The length of the LCS (tab) is: " << lcsTab(s1, s2, n, m) << endl;
}