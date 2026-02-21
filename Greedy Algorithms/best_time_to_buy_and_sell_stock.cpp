#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> prices) {
    int lowest = prices[0];
    int maxProfit = 0;

    for(int i = 0; i < prices.size(); i++) {
        maxProfit = max(maxProfit, prices[i] - lowest);
        lowest = min(lowest, prices[i]);
    }
    return maxProfit;
}

int main() {
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<int> prices = {7, 6, 4, 3, 1};
    int profit = maxProfit(prices);
    cout << "The maximum profit that can be earned is " << profit << endl;
}