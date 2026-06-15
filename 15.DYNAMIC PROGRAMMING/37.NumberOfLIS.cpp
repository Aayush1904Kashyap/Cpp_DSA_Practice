#include <bits/stdc++.h>
using namespace std;



int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);

    int maxi = 1;

    for (int i = 0; i < n; ++i) {
        for (int prev = 0; prev < i; ++prev) {

            if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];
            }

            else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i]) {
                cnt[i] += cnt[prev];
            }
        }

        maxi = max(maxi, dp[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] == maxi) {
            ans += cnt[i];
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<findNumberOfLIS(nums)<<endl;

    return 0;

}