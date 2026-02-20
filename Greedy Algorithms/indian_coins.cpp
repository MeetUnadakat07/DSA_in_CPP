#include<iostream>
#include<vector>
using namespace std;

int countCoins(vector<int> coins, int value) {
    int count = 0;
    for(int i = coins.size() - 1; i >= 0 && value > 0; i--) {
        if(value > coins[i]) {
            count += value / coins[i];
            value %= coins[i];
        }
    }
    return count;
}

int main() {
     vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
     int value = 590;
     int count = countCoins(coins, value);
     cout << "The minimum number of coins required is: " << count << endl;
}   