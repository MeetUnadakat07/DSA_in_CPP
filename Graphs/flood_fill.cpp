#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<int>> &image, vector<vector<bool>> &vis, int newColor, int oldColor) {
    vis[row][col] = true;
    image[row][col] = newColor;

    // up
    if(row > 0 && !vis[row - 1][col] && image[row - 1][col] == oldColor) {
        dfs(row - 1, col, n, m, image, vis, newColor, oldColor);
    }
    // down
    if(row < n - 1 && !vis[row + 1][col] && image[row + 1][col] == oldColor) {
        dfs(row + 1, col, n, m, image, vis, newColor, oldColor);
    }
    //left
    if(col > 0 && !vis[row][col - 1] && image[row][col - 1] == oldColor) {
        dfs(row, col - 1, n, m, image, vis, newColor, oldColor);
    }
    // right
    if(col < m - 1 && !vis[row][col + 1] && image[row][col + 1] == oldColor) {
        dfs(row, col + 1, n, m, image, vis, newColor, oldColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size();
    int m = image[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    dfs(sr, sc, n, m, image, vis, newColor, image[sr][sc]);
    return image;
}

int main() {
    vector<vector<int>> image = {{1, 1, 1},
                                {1, 1, 0},
                                {1, 0, 1}};

    floodFill(image, 1, 1, 2);

    cout << "The updated image is: " << endl;
    for(int i = 0; i < image.size(); i++) {
        for(int j = 0; j < image[0].size(); j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}