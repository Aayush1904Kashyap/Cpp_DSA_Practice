#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        dp[i][0]=matrix[i][0];
    }
    for(int i=0;i<m;i++){
        dp[0][i]=matrix[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]){
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }else{
                dp[i][j]=0;
            }
        }
    }
    int total_sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            total_sum += dp[i][j];
        }
    }
    return total_sum;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = countSquares(matrix);
    cout << result << endl;

    return 0;
}