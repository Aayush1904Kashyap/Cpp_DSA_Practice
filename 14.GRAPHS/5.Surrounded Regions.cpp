#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vis[row][col] = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
            board[nr][nc] == '0' && !vis[nr][nc]) {
            dfs(nr, nc, vis, board);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Mark boundary-connected '0's
    for (int j = 0; j < m; j++) {
        if (board[0][j] == '0' && !vis[0][j])
            dfs(0, j, vis, board);
        if (board[n-1][j] == '0' && !vis[n-1][j])
            dfs(n-1, j, vis, board);
    }

    for (int i = 0; i < n; i++) {
        if (board[i][0] == '0' && !vis[i][0])
            dfs(i, 0, vis, board);
        if (board[i][m-1] == '0' && !vis[i][m-1])
            dfs(i, m-1, vis, board);
    }

    // Convert unvisited '0's to '1'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '0' && !vis[i][j])
                board[i][j] = '1';
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    solve(arr);

    // Output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
