/*
Problem statement
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.
*/

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int f(int i, int s, vector<int>& arr){
    if(i==0){
        if(s==0 && arr[0]==0) return 2;
        if(s==0 || s==arr[0]) return 1;
        return 0;
    }
    int notPick = f(i-1, s, arr);
    int pick = 0;
    if(arr[i]<=s){
        pick = f(i-1, s-arr[i], arr);
    }
    return (pick + notPick) % mod;
}

int findWays1(vector<int>& arr, int k)
{
	// Write your code here.

    return f(arr.size()-1, k, arr);
}

int fdp(int i, int s, vector<int>& arr, vector<vector<int>>& dp){
    if(i==0){
        if(s==0 && arr[0]==0) return 2;
        if(s==0 || s==arr[0]) return 1;
        return 0;
    }
    if(dp[i][s]!=-1) return dp[i][s];
    int notPick = fdp(i-1, s, arr, dp);
    int pick = 0;
    if(arr[i]<=s){
        pick = fdp(i-1, s-arr[i], arr, dp);
    }
    return dp[i][s] = (pick + notPick) % mod;
}

int findWays2(vector<int>& arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return fdp(n-1, k, arr, dp);
}

int findWays3(vector<int>& arr, int k)
{
    int n= arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    if(arr[0]==0){
        dp[0][0] = 2;
    }
    else{
        dp[0][0] = 1;
    }


    if(arr[0]!=0 && arr[0]<=k){
        dp[0][arr[0]] = 1;
    }
    for(int i=1;i<n;i++){
        for(int target=0;target<=k;target++){
            int notPick = dp[i-1][target];
            int pick = 0;
            if(arr[i]<=target){
                pick = dp[i-1][target-arr[i]];
            }
            dp[i][target] = (pick + notPick) % mod;
        }
    }
    return dp[n-1][k];
}

int findWays4(vector<int>& arr, int k)
{
    int n= arr.size();
    vector<int> prev(k+1, 0), curr(k+1, 0);
    prev[0] = curr[0] = 1;
    if(arr[0]<=k){
        prev[arr[0]] = 1;
    }
    for(int i=1;i<n;i++){
        for(int target=0;target<=k;target++){
            int notPick = prev[target];
            int pick = 0;
            if(arr[i]<=target){
                pick = prev[target-arr[i]];
            }
            curr[target] = (pick + notPick) % mod;
        }
        prev = curr;
    }
    return prev[k];
}





int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findWays1(arr,k)<<endl;
    cout<<findWays2(arr,k)<<endl;
    cout<<findWays3(arr,k)<<endl;
    cout<<findWays4(arr,k)<<endl;

}

/*
Pattern for counting recursion:
generally in base cases we return 1 when target is 0 and return 0 when target is negative or index is out of bounds.

express in terms of index and target:
explore all possibilities of taking and not taking the current element 
add them up.

f(n-1,s) tells us the number of ways to achieve sum s using first n-1 elements (not taking current element)

in case of zeroes in the array, 
we need to be careful as they can be included or excluded without affecting the sum,
 which can lead to multiple combinations. 
 In such cases, we can count the number of zeros and 
 multiply the result by 2 raised to the power of the count of zeros
  to account for all combinations of including or excluding those zeros.
  mathematically, if there are 'z' zeros in the array, 
  we can multiply the final count of subsets by 2^z
   to account for the combinations of including or excluding each zero.
*/