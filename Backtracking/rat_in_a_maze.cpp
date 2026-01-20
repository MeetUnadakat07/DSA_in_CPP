#include <iostream>
#include<vector>
using namespace std;

void mazeSolver(vector<vector<int>> &maze, int row, int col, string path, vector<string> &ans) {
    int n = maze.size();
    // Check for the boundary conditions, blocked cells and visited cells 
    if(row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || maze[row][col] == -1) {
        return;
    }

    // Destination is reached 
    if(row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    // We have visited
    maze[row][col] = -1;
    
    // Make the calls for going in all four directions 
    mazeSolver(maze, row + 1, col, path + "D", ans);
    mazeSolver(maze, row - 1, col, path + "U", ans);
    mazeSolver(maze, row, col + 1, path + "R", ans);
    mazeSolver(maze, row, col - 1, path + "L", ans);

    // We will again set the value to 1 for the next calls to get a new route 
    maze[row][col] = 1;
}

vector<string> findPath(vector<vector<int>> &maze) {
    vector<string> ans;
    string path = "";
    int n = maze.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    mazeSolver(maze, 0, 0, path, ans);
    return ans;
}

int main() {
    vector<vector<int>> maze = {
                            {1, 0, 0, 0},
                            {1, 1, 0, 1},
                            {1, 1, 0, 0},
                            {0, 1, 1, 1}
                        };
    vector<string> ans = findPath(maze);
    for(string path : ans) {
        cout << path << endl;
    }
}