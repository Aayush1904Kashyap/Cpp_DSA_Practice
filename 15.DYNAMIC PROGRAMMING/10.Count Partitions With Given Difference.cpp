/*
Problem statement
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.
Note that the sum of the elements of an empty subset is 0.
*/

#include <bits/stdc++.h> 
using namespace std;

int mod = 1e9 + 7;

int findWays2(vector<int>& arr, int k)
{
    // Write your code here.
    
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

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if(totalSum-d < 0 || (totalSum-d)%2 != 0) return 0;
    int s2 = (totalSum-d)/2;
    return findWays2(arr, s2);
}

int main(){
    int n,d;
    cin>>n>>d;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countPartitions(n,d,arr)<<endl;

}