#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lcsRec(string s1, string s2, int n, int m, int &ans) {
    if(n < 0 || m < 0) return 0;
    
    int match = 0;
    if(s1[n] == s2[m]) {
        match = 1 + lcsRec(s1, s2, n - 1, m - 1, ans);
        ans = max(ans, match);
    }

    lcsRec(s1, s2, n - 1, m, ans);
    lcsRec(s1, s2, n, m - 1, ans);
    return match;
}

int longestCommonSubstring(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main() {
    string s1 = "abcde";
    string s2 = "abgce";

    cout << "The length of the longest common substring is: " << longestCommonSubstring(s1, s2) << endl;
    int ans = 0;
    cout << lcsRec(s1, s2, s1.size() - 1, s2.size() - 1, ans) << endl;
}