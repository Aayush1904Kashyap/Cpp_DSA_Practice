#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // dp[row][col1][col2] initialized to -1
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // Starting points: (0,0) and (0, m-1)
    dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];

    for (int i = 0; i < n - 1; i++) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (dp[i][j1][j2] == -1) continue;

                // Possible moves: -1, 0, +1 for each player
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;

                        if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                            int candies = (nj1 == nj2) ? grid[i + 1][nj1] : (grid[i + 1][nj1] + grid[i + 1][nj2]);
                            dp[i + 1][nj1][nj2] = max(dp[i + 1][nj1][nj2], dp[i][j1][j2] + candies);
                        }
                    }
                }
            }
        }
    }

    int max_candies = 0;
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            max_candies = max(max_candies, dp[n - 1][j1][j2]);
        }
    }
    return max_candies;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << solve() << endl;
    return 0;
}