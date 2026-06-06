#include <bits/stdc++.h>
using namespace std;





int minimumDifference1(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0); 
    int minDiff = 1e9;
    int n = nums.size();
    int k=total;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    if (nums[0] <= k) {
        dp[0][nums[0]] = true;
    }
    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool notTake =dp[i-1][target];
            bool take=false;
            if(nums[i]<=target){
                take=dp[i-1][target-nums[i]];
            }
            dp[i][target]=take || notTake;
        }
    }
    for (int s1 = 0; s1 <= total/2; s1++) {
        if (dp[n-1][s1]) {
            int s2 = total - s1;
            minDiff = min(minDiff, abs(s1 - s2));
        }
    }
    return minDiff;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<minimumDifference1 (nums);
}