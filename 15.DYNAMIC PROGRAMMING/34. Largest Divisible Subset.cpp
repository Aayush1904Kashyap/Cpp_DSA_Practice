#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<int> dp(n, 1), hash(n);

    int last = 0;
    int maxi = 1;

    for (int i = 1; i < n; ++i) {
        hash[i] = i;

        for (int prev = 0; prev < i; ++prev) {
            if (nums[i] % nums[prev]==0 && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }

        if (dp[i] > maxi) {
            maxi = dp[i];
            last = i;   // store index of LIS ending
        }
    }

    // Reconstruct LIS
    vector<int> lis;
    lis.push_back(nums[last]);

    while (hash[last] != last) {
        last = hash[last];
        lis.push_back(nums[last]);
    }

    reverse(lis.begin(), lis.end());
    return lis;
}

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }


    vector<int> ans = largestDivisibleSubset(nums);

    cout << "Longest Divisible Subset: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}