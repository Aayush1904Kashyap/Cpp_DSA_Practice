#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int oldColor, int dr[], int dc[]) {
    
    ans[row][col] = color;
    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; i++) {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == oldColor && ans[nrow][ncol] != color) {
            dfs(nrow, ncol, ans, image, color, oldColor, dr, dc);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size(), m = image[0].size();
    int oldColor = image[sr][sc];
    if (oldColor == color) return image; 
    vector<vector<int>> ans = image;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    dfs(sr, sc, ans, image, color, oldColor, dr, dc);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Example: start from (1,1) and change to color=2
    vector<vector<int>> result = floodFill(arr, 1, 1, 2);

    // Print result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
