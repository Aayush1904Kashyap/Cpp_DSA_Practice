#include <bits/stdc++.h>
using namespace std;



int longestBitonicSubsequence(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp1(n, 1);   // LIS
    vector<int> dp2(n, 1);   // LDS

    // LIS from left to right
    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[prev] < nums[i] && dp1[prev] + 1 > dp1[i]) {
                dp1[i] = dp1[prev] + 1;
            }
        }
    }

    int maxi = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int prev = n - 1; prev > i; prev--) {
            if (nums[prev] < nums[i] && dp2[prev] + 1 > dp2[i]) {
                dp2[i] = dp2[prev] + 1;
            }
        }
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}

int main() {
    int n;
    cin >> n;          

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = longestBitonicSubsequence(nums);
    cout << ans << endl;

    return 0;
}