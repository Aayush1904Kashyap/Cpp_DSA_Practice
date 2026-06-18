/*
Problem statement
Given a chain of matrices A1, A2, A3,.....An. 
Your task is to find out the minimum cost to multiply these matrices. 
The cost of matrix multiplication is defined as the number of scalar multiplications. 
A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.
For example:
For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]
Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.
*/

#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<int> &arr){
    if(i==j) return 0;
    int mini=1e9;
    for(int k=i;k<j;++k){
        int steps=(arr[i-1]*arr[k]*arr[j]) + f(i,k,arr) + f(k+1,j,arr);
        if(steps<mini)mini=steps;
    }
    return mini;
}

int matrixMultiplication1(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    return f(1,n-1,arr);
}

int fdp(int i,int j,vector<int> &arr,vector<vector<int>>& dp){
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini=1e9;
    for(int k=i;k<j;++k){
        int steps=(arr[i-1]*arr[k]*arr[j]) + fdp(i,k,arr,dp) + fdp(k+1,j,arr,dp);
        if(steps<mini)mini=steps;
    }
    return dp[i][j]=mini;
}

int matrixMultiplication2(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return fdp(1,n-1,arr,dp);
}
int matrixMultiplication3(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    
    vector<vector<int>>dp(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }

    for(int i=n-1;i>0;i--){
        for(int j=i+1;j<n;j++){
            int mini=1e9;
            for(int k=i;k<j;++k){
                int steps=(arr[i-1]*arr[k]*arr[j]) + dp[i][k]+dp[k+1][j];
                if(steps<mini)mini=steps;
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

 
    cout << matrixMultiplication1(arr) << endl;
    cout << matrixMultiplication2(arr) << endl;
    cout << matrixMultiplication3(arr) << endl;

    return 0;
}

/*

Partition DP
1. Start with entire block/array and mark with start pointer,i and end pointer,j
2. Try All Partition---->Run a loop to try all partition
3. Return the best possible 2 partition 

f(i,j) return the min multiplication to multiply matrix i to matrix j
*/