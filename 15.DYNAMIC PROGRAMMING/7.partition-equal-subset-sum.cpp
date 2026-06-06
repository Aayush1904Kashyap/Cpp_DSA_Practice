#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK3(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false);
    vector<bool> curr(k + 1, false);
    prev[0] = true;
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }
    for (int i = 1; i < n; i++) {
        curr[0] = true;
        for (int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if (arr[i] <= target) {
                take = prev[target - arr[i]];
            }
            curr[target] = take || notTake;
        }
        prev = curr;
    }
    return prev[k];
}


bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) {
        return false;
    }
    int target = total / 2;
    int n = nums.size();
 return subsetSumToK3(n, target, nums);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<canPartition(nums);
}