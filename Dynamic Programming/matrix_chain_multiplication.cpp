#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int mcmRec(vector<int> &arr, int i, int j) {
    if(i == j) return 0;

    int ans = INT_MAX;
    for(int k = i; k < j; k++) {
        // from i to k
        int cost1 = mcmRec(arr, i, k);
        // from k + 1 to j
        int cost2 = mcmRec(arr, k + 1, j);

        // current partition cost
        int currCost = cost1 + cost2 + (arr[i - 1] * arr[k] * arr[j]);

        ans = min(ans, currCost);
    }
    return ans;
}

int mcmMemo(vector<int> &arr, vector<vector<int>> &dp, int i, int j) {
    if(i == j) return 0;

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = INT_MAX;
    for(int k = i; k < j; k++) {
        int cost1 = mcmMemo(arr, dp, i, k);
        int cost2 = mcmMemo(arr, dp, k + 1, j);

        int currCost = cost1 + cost2 + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }

    dp[i][j] = ans;
    return ans;
}

int mcmTab(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int len = 2; len < n; len++) {
        for(int i = 1; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++) {
                int cost1 = dp[i][k];
                int cost2 = dp[k + 1][j];

                int currCost = cost1 + cost2 + (arr[i - 1] * arr[k] * arr[j]);
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    int n = arr.size();
    
    cout << "The minimum number of multiplication needed to multiply the matrices is " << mcmRec(arr, 1, n - 1) << endl;
    
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout << "The minimum number of multiplication needed to multiply the matrices is " << mcmMemo(arr, dp, 1, n - 1) << endl;
    
    cout << "The minimum number of multiplication needed to multiply the matrices is " << mcmTab(arr) << endl;
}