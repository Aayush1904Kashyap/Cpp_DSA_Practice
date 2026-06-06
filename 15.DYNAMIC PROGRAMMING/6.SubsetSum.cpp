/*
DP on Subsequences/Subsets
Subsequences: it is a sequence that can be derived from another sequence by deleting some or no elements 
without changing the order of the remaining elements. 
For example, "abc", "abg", "bdf", "aeg", "acefg", .. etc are subsequences of "abcdefg". 
So, a subsequence maintains the relative order of the characters but not necessarily contiguous.

Problem:You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. 
Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
*/

#include <bits/stdc++.h> 
using namespace std;

bool f(int i,int target,vector<int>& arr){
    if(target==0){
        return true;
    }
    if(i==0){
        return arr[0]==target;
    }
    bool notTake=f(i-1,target,arr);
    bool take=false;
    if(arr[i]<=target){
        take=f(i-1,target-arr[i],arr);
    }
    return take || notTake;

    //TC: O(2^N) SC: O(N)+O(N) for recursion stack
}

bool fdp(int i,int target,vector<int>& arr,vector<vector<int>>& dp){
    if(target==0){
        return true;
    }
    if(i==0){
        return arr[0]==target;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    bool notTake=fdp(i-1,target,arr,dp);
    bool take=false;
    if(arr[i]<=target){
        take=fdp(i-1,target-arr[i],arr,dp);
    }
    return dp[i][target]=take || notTake;

    //TC: O(N*K) SC: O(N*K)+O(N) for recursion stack
}

bool subsetSumToK1(int n, int k, vector<int> &arr) {
    return f(n-1,k,arr);
}

bool subsetSumToK2(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return fdp(n - 1, k, arr, dp);
}

bool subsetSumToK3(int n, int k, vector<int> &arr) {
    //dp[i][target]
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    if (arr[0] <= k) {
        dp[0][arr[ 0]] = true;
    }

    //no of nested loops will be equal to the no of base cases, here we have two base cases, so we will have two nested loops
    //if from n-1 we have to reach 0, then we will have to run the loop from 1 to n-1, and if from k we have to reach 0, then we will have to run the loop from 1 to k
    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool notTake =dp[i-1][target];
            bool take=false;
            if(arr[i]<=target){
                take=dp[i-1][target-arr[i]];
            }
            dp[i][target]=take || notTake;
        }
    }
    return dp[n-1][k];

    //TC: O(N*K) SC: O(N*K)

}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (subsetSumToK1(n, k, arr)) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << endl;
    if (subsetSumToK2(n, k, arr)) {
        cout << "true";
    } else {
        cout << "false";
    }
        cout << endl;
    if (subsetSumToK3(n, k, arr)) {
        cout << "true";
    } else {
        cout << "false";
    }
}

/*
all the subsequence problems have the same structure of recursion, 
we have two choices for each element, either we take it or we do not take it.
*/