#include <bits/stdc++.h>
using namespace std;

int f(int i,int prev,vector<int>& nums){
    //f(3,0)--length of LIS starting from 3rd index whose previous index is 0
    int n=nums.size();
    if(i==n) return 0;
    
    int len=INT_MIN;
    int notTake=f(i+1,prev,nums);
    int take=0;
    if(prev== -1 || nums[i]>nums[prev]){
       take= 1+ f(i+1,i,nums);
    }
    len=max(notTake,take);
    return len;
}

int maxL(vector<int>& nums){
    return f(0,-1,nums);
}

int fdp(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
    //f(3,0)--length of LIS starting from 3rd index whose previous index is 0
    int n=nums.size();
    if(i==n) return 0;

    if(dp[i][prev+1] != -1){
        return dp[i][prev+1];
    }
    
    int len=INT_MIN;
    int notTake=f(i+1,prev,nums);
    int take=0;
    if(prev== -1 || nums[i]>nums[prev]){
       take= 1+ f(i+1,i,nums);
    }
    len=max(notTake,take);
    return dp[i][prev+1]=len;
}

int maxL1(vector<int>& nums){
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return fdp(0,-1,nums,dp);
}

int maxL2(vector<int>& nums){
    int n=nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    int len=INT_MIN;
    for(int i=n-1;i>=0;--i){
        for(int prev=i-1;prev>=-1;--prev){
            int notTake=dp[i+1][prev+1];
            int take=0;
            if(prev== -1 || nums[i]>nums[prev]){
                take= 1+ dp[i+1][i+1];
             }
            len=max(notTake,take);
            dp[i][prev+1]=len;
        }
    }
    return dp[0][0];
    
}

int maxL3(vector<int>& nums){
    int n=nums.size();
    vector<int>next(n+1,0),curr(n+1,0);
    int len=INT_MIN;
    for(int i=n-1;i>=0;--i){
        for(int prev=i-1;prev>=-1;--prev){
            int notTake=next[prev+1];
            int take=0;
            if(prev== -1 || nums[i]>nums[prev]){
                take= 1+ next[i+1];
             }
            len=max(notTake,take);
            curr[prev+1]=len;
        }
        next=curr;
    }
    return next[0];
    
}

int maxL4(vector<int>& nums){
    int n=nums.size();
    vector<int>dp(n,1);

    int maxi=1;

    for(int i=0;i<n;++i){
        for(int prev=0;prev<i;++prev){
            if(nums[prev]<nums[i]){
                dp[i]=max(1+dp[prev],dp[i]);
            }
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
    
}

int maxL5(vector<int>& nums){
    int n=nums.size();
    vector<int>temp;
    temp.push_back(nums[0]);
    for (int i = 0; i < n; ++i){
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
        }else{
            int ind=lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
            temp[ind]=nums[i];


        }
    }

    return temp.size();
}

vector<int> LIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);

    int last = 0;
    int maxi = 1;

    for (int i = 0; i < n; ++i) {
        hash[i] = i;

        for (int prev = 0; prev < i; ++prev) {
            if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
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

    cout<<maxL(nums)<<endl;
    cout<<maxL1(nums)<<endl;
    cout<<maxL2(nums)<<endl;
    cout<<maxL3(nums)<<endl;
    cout<<maxL4(nums)<<endl;
    cout<<maxL5(nums)<<endl;

    vector<int> ans = LIS(nums);

    cout << "Longest Increasing Subsequence: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;

}