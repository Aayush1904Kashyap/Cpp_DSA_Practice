#include <bits/stdc++.h>
using namespace std;

     bool isTrionic(vector<int>& nums, int l, int r) {
        int i = l;
        bool up1 = false, down = false, up2 = false;

        while (i < r && nums[i] < nums[i + 1]) {
            i++;
            up1 = true;
        }

        while (i < r && nums[i] > nums[i + 1]) {
            i++;
            down = true;
        }

        while (i < r && nums[i] < nums[i + 1]) {
            i++;
            up2 = true;
        }

        return (i == r) && up1 && down && up2;
    }

    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        // correct prefix sum
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<long long> dp(n, LLONG_MIN);

        for (int i = 3; i < n; i++) {

            long long ans = dp[i - 1];

            for (int j = 0; j < i; j++) {

                if (isTrionic(nums, j, i)) {

                    long long curr = prefix[i + 1] - prefix[j];

                    ans = max(ans, curr);
                }
            }

            dp[i] = ans;
        }

        return dp[n - 1];
    }

    
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maxSumTrionic(nums)<<endl;
}

