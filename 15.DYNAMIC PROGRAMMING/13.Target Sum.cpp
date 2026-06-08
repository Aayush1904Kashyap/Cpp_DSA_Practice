#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int helper(vector<int>& arr, int k)
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

int findTargetSumWays(vector<int>& nums, int target) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if(totalSum-target < 0 || (totalSum-target)%2 != 0) return 0;
    int s2 = (totalSum-target)/2;
    return helper(nums, s2);
}

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<findTargetSumWays(nums, target)<<endl;
}

