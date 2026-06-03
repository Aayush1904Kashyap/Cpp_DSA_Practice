#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    int n=triangle.size();

    if(i==n-1){
        return triangle[n-1][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int down=triangle[i][j]+f(i+1,j,triangle,dp);
    int diagonal=triangle[i][j]+f(i+1,j+1,triangle,dp);

    return dp[i][j]=min(down,diagonal);
}

    int minimumTotalMEMO(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0, 0, triangle, dp);
    }

    int minimumTotalTAB(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }

    int minimumTotalTAB2(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n, -1);

        for (int j = 0; j < n; j++) {
            prev[j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, -1);
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j + 1];
                curr[j] = min(down, diagonal);
            }
            prev = curr;
        }
        return prev[0];
    }

int main(){
    int n;
    cin>>n;
    vector<vector<int>> triangle(n);
    for(int i=0;i<n;i++){
        triangle[i].resize(i+1);
        for(int j=0;j<=i;j++){
            cin>>triangle[i][j];
        }
    }
    cout<<minimumTotalMEMO(triangle)<<endl;
    cout<<minimumTotalTAB(triangle)<<endl;
    cout<<minimumTotalTAB2(triangle)<<endl;
    return 0;
}


//if recursion or memoization is from top to bottom then tabulation is from bottom to top and if recursion or memoization is from bottom to top then tabulation is from top to bottom.