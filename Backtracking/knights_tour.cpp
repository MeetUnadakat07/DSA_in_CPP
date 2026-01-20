#include<iostream>
using namespace std;
const int n = 6;            // Will not work for 8 as it will take a very huge time

// Thw moves of the knight 
int moveX[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int moveY[8] = {2, -2, 2, -2, 1, -1, 1, -1};

bool isSafe(int board[n][n], int row, int col) {
    // Check if we are into the board boundaries and if it is unvisited 
    if(row >= 0 && col >= 0 && row < n && col < n && board[row][col] == -1) {
        return true;
    }
    return false;
}

bool knightsTour(int board[n][n], int row, int col, int moveCount) {
    if(moveCount == n * n) {
        return true;
    }
    for(int k = 0; k < 8; k++) {
        int newRow = row + moveX[k];
        int newCol = col + moveY[k];

        if(isSafe(board, newRow, newCol)) {
            board[newRow][newCol] = moveCount;
            if(knightsTour(board, newRow, newCol, moveCount + 1)) {
                return true;
            }
            board[newRow][newCol] = -1;
        }
    }
    return false;
}

int main() {
    
    int board[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = -1;
        }
    }
    board[0][0] = 0;

    if(knightsTour(board, 0, 0, 1)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cout << "No solution exists" << endl;;
    }
}