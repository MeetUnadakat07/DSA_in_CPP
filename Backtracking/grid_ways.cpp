#include<iostream>
using namespace std;

int ways(int row, int col, int n, int m, string direction) {
    // Reached the destination 
    if(row == n - 1 && col == m - 1) {
        cout << direction << endl;
        return 1;
    }

    // Reached the last row or col 
    if(row >= n || col >= m) {
        return 0;
    }

    // Right 
    int val1 = ways(row, col + 1, n, m, direction + "R ");

    // Left 
    int val2 = ways(row + 1, col, n, m, direction + "D ");

    return val1 + val2;
}

int main() {
    int n = 3;
    int m = 3;
    string dir = "";
    int ans = ways(0, 0, n, m, dir);
    cout << ans << endl;
}