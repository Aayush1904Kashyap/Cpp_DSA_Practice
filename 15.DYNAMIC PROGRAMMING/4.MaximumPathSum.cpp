/*Problem statement
You have been given an N*M matrix filled with integer numbers, 
find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. 
So from a particular cell (row, col), we can move in three directions i.e.
Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)*/

#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>> &matrix){
    int n=matrix.size();
    int m=matrix[0].size();

    if(j<0 || j>=m){
        return -1e9;
    }
    if(i==0){
        return matrix[0][j];
    }

    int straight=matrix[i][j]+f(i-1,j,matrix);
    int leftDiagonal=matrix[i][j]+f(i-1,j-1,matrix);
    int rightDiagonal=matrix[i][j]+f(i-1,j+1,matrix);

    return max(straight,max(leftDiagonal,rightDiagonal));
}

int getMaxPathSumUsingRecursion(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    int maxi=INT_MIN;
    for(int j=0;j<m;j++){
        maxi=max(maxi,f(n-1,j,matrix));
    }
    return maxi;
}

int fdp(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    int n=matrix.size();
    int m=matrix[0].size();

    if(j<0 || j>=m){
        return -1e9;
    }
    if(i==0){
        return matrix[0][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int straight=matrix[i][j]+fdp(i-1,j,matrix,dp);
    int leftDiagonal=matrix[i][j]+fdp(i-1,j-1,matrix,dp);
    int rightDiagonal=matrix[i][j]+fdp(i-1,j+1,matrix,dp);

    return dp[i][j]=max(straight,max(leftDiagonal,rightDiagonal));
}

int getMaxPathSumUsingMemoization(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    int maxi=INT_MIN;
    for(int j=0;j<m;j++){
        maxi=max(maxi,fdp(n-1,j,matrix,dp));
    }
    return maxi;
}

int getMaxPathSumUsingTabulation(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    vector<vector<int>> dp(n,vector<int>(m,-1));

    for(int j=0;j<m;j++){
        dp[0][j]=matrix[0][j];
    }

   for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int straight=matrix[i][j]+dp[i-1][j];
            int leftDiagonal=-1e9;
            int rightDiagonal=-1e9;
            
            if(j-1 >=0){
                leftDiagonal=matrix[i][j]+dp[i-1][j-1];
            }
            if(j+1 < m){
                rightDiagonal=matrix[i][j]+dp[i-1][j+1];
            }

            dp[i][j]=max(straight,max(leftDiagonal,rightDiagonal));
        }
   }
    int maxi=INT_MIN;
    for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
    }
    return maxi;
}

int getMaxPathSumUsingSpaceOptimization(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    vector<int> prev(m,-1);

    for(int j=0;j<m;j++){
        prev[j]=matrix[0][j];
    }

   for(int i=1;i<n;i++){
        vector<int> curr(m,-1);
        for(int j=0;j<m;j++){
            int straight=matrix[i][j]+prev[j];
            int leftDiagonal=-1e9;
            int rightDiagonal=-1e9;
            
            if(j-1 >=0){
                leftDiagonal=matrix[i][j]+prev[j-1];
            }
            if(j+1 < m){
                rightDiagonal=matrix[i][j]+prev[j+1];
            }

            curr[j]=max(straight,max(leftDiagonal,rightDiagonal));
        }
        prev=curr;
   }
    int maxi=INT_MIN;
    for(int j=0;j<m;j++){
        maxi=max(maxi,prev[j]);
    }
    return maxi;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << getMaxPathSumUsingRecursion(matrix) << endl;
    cout << getMaxPathSumUsingMemoization(matrix) << endl;
    cout << getMaxPathSumUsingTabulation(matrix) << endl;
    cout << getMaxPathSumUsingSpaceOptimization(matrix) << endl;
    return 0;
}


/*recursion general steps
S1:express the problem in terms of index and write the base case
    base cases can be destination or out of bound cases
S2:try all possible ways
S3:return the best among all
*/