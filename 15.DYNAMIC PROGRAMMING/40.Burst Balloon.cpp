#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<int>& nums){
    if(i>j)return 0;
    int maxi=INT_MIN;
    for(int ind=i;ind<=j;++ind){
        int cost= nums[i-1]*nums[ind]*nums[j+1] + f(i,ind-1,nums) + f(ind+1,j,nums);
        maxi=max(cost,maxi);
    }
    return maxi;
}

// int maxCoins(vector<int>& nums) {
//     int n=nums.size();
//     nums.push_back(1);
//     nums.insert(nums.begin(),1);
//     return f(1,n,nums);
    
// }

int maxCoins(vector<int>& nums) {
    int n=nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);

    vector<vector<int>> dp(n+2,vector<int>(n+2,0));

    for(int i=n;i>=1;--i){
        for(int j=1;j<=n;j++){
            if(i>j) continue;
            int maxi=INT_MIN;
            for(int ind=i;ind<=j;++ind){
                int cost= nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1]+dp[ind+1][j];
                maxi=max(cost,maxi);
            }
            dp[i][j]=maxi;
        }
    }
    return dp[1][n];
    
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxCoins(nums) << endl;

    return 0;
}