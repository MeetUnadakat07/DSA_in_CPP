#include<iostream>
using namespace std;
const int n = 3;

bool isValid(int grid[n][n], int row, int col, int expectedVal) {
    if(row < 0 || col < 0 || row >= n || col >= n) {
        return false;
    }
    if(grid[row][col] != expectedVal) {
        return false;
    }
    if(expectedVal >= (n * n) - 1) {
        return true;
    } 
    bool val1 = isValid(grid, row + 2, col + 1, expectedVal + 1);
    bool val2 = isValid(grid, row + 2, col - 1, expectedVal + 1);
    bool val3 = isValid(grid, row - 2, col - 1, expectedVal + 1);
    bool val4 = isValid(grid, row - 2, col + 1, expectedVal + 1);
    bool val5 = isValid(grid, row - 1, col + 2, expectedVal + 1);
    bool val6 = isValid(grid, row - 1, col - 2, expectedVal + 1);
    bool val7 = isValid(grid, row + 1, col - 2, expectedVal + 1);
    bool val8 = isValid(grid, row + 1, col + 2, expectedVal + 1);
    return val1 || val2 || val3 || val4 || val5 || val6 || val7 || val8;
}

int main() {
    int grid[3][3] = {{0, 3, 6}, {5, 8, 1}, {2, 7, 4}};
    if(isValid(grid, 0, 0, 0)) {
        cout << "The given configuration shows valid knight's tour." << endl;
    } else {
        cout << "The given configuration doen not show valid knight's tour." << endl;
    }
}