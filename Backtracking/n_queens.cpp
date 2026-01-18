#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> board) {
    int n = board.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j ++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<char>> board, int row, int col) {
    int n = board.size();
    // To check the rows 
    for(int i = 0; i < n; i++) {
        if(board[row][i] == 'Q') {
            return false;
        }
    }

    // To check the cols 
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    // To check the left diagonal 
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    // To check the right diagonal 
    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    return true;

}

void nQueens(vector<vector<char>> board, int row) {   // ith row pe ith queen ko place karvana hai
    int n = board.size();
    if(row == n) {
        printBoard(board);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(isSafe(board, row, i)) {
            board[row][i] = 'Q';
            nQueens(board, row + 1);
            board[row][i] = '.';        // backtrack karte time pe queen ko hata dena hai jisse naya call alag jagah par add kar de
        }
    }
}

int main() {
    int n;
    // Creating the board 
    vector<vector<char>> board;
    cout << "Enter the size of the board (no of rows / cols): ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        vector<char> newRow;
        for(int j = 0; j < n; j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    nQueens(board, 0);
}