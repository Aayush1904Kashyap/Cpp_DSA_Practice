#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& nums) {
    
    int n = nums.size();
    int m = nums[0].size();

    if (i >= n || j >= m) {
        return 1e9;
    }

    if (i == n - 1 && j == m - 1) {
        return max(1, 1 - nums[i][j]);
    }

    int right = f(i, j + 1, nums);
    int down = f(i + 1, j, nums);

    int need = min(right, down);

    return max(1, need - nums[i][j]);
}

int calculateMinimumHP1(vector<vector<int>>& dungeon) {
    return f(0, 0, dungeon);
}

int fdp(int i, int j, vector<vector<int>>& nums,vector<vector<int>>& dp) {
    
    int n = nums.size();
    int m = nums[0].size();

    if (i >= n || j >= m) {
        return 1e9;
    }

    if(dp[i][j] != -1)return dp[i][j];

    if (i == n - 1 && j == m - 1) {
        return max(1, 1 - nums[i][j]);
    }


    int right = fdp(i, j + 1, nums,dp);
    int down = fdp(i + 1, j, nums,dp);

    int need = min(right, down);

    return dp[i][j]=max(1, need - nums[i][j]);
}

int calculateMinimumHP2(vector<vector<int>>& dungeon) {
    int n = dungeon.size();
    int m = dungeon[0].size();    
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return fdp(0, 0, dungeon,dp);
}

int calculateMinimumHP3(vector<vector<int>>& nums) {
    int n = nums.size();
    int m = nums[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

    // virtual boundary
    dp[n][m - 1] = 1;
    dp[n - 1][m] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {

            int need = min(dp[i + 1][j], dp[i][j + 1]);

            dp[i][j] = max(1, need - nums[i][j]);
        }
    }

    return dp[0][0];
}

int main() {
    
    int m, n;
    cin >> m >> n;

    vector<vector<int>> dungeon(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dungeon[i][j];
        }
    }

    cout << calculateMinimumHP1(dungeon) << endl;
    cout << calculateMinimumHP2(dungeon) << endl;
    cout << calculateMinimumHP3(dungeon) << endl;

    return 0;
}