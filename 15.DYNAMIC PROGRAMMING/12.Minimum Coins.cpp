#include <bits/stdc++.h>
using namespace std;

int f(int i,int T,vector<int>& coins){
    if(i==0){
        if(T%coins[0]==0) {return T/coins[0];
    }else{
        return 1e9;
    }
}
    //if there is infinite supply of something stand on same index and alter target
    int notTake=0+f(i-1,T,coins);
    int Take=INT_MAX;
    if(coins[i]<=T){
        Take=1+f(i,T-coins[i],coins);
    }
    return min(notTake,Take);
}

int coinChange1(vector<int>& coins, int amount) {
    int n=coins.size();    
    int ans= f(n-1,amount,coins);
    if(ans>=1e9)return -1;
    return ans;
}

int fdp(int i,int T,vector<int>& coins,vector<vector<int>>& dp){
    if(i==0){
        if(T%coins[0]==0) {return T/coins[0];
    }else{
        return 1e9;
    }
}
    if(dp[i][T]!= -1) return dp[i][T];
    //if there is infinite supply of something stand on same index and alter target
    int notTake=0+f(i-1,T,coins);
    int Take=INT_MAX;
    if(coins[i]<=T){
        Take=1+f(i,T-coins[i],coins);
    }
    return dp[i][T]=min(notTake,Take);
}

int coinChange2(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,-1));    
    int ans= fdp(n-1,amount,coins,dp);
    if(ans>=1e9)return -1;
    return ans;
}

int coinChange3(vector<int>& coins, int amount) {
    int n=coins.size();
    int T=amount;
    vector<vector<int>>dp(n,vector<int>(amount+1,0));    
   
    for(int t=0;t<=T;++t){
        if(t%coins[0]==0){
            dp[0][t]=t/coins[0];
        }else{
            dp[0][t]=1e9;
        }
    }

    for(int i=1;i<n;++i){
        for(int t=0;t<=T;++t){
            int notTake=0+dp[i-1][t];
            int Take=INT_MAX;
            if(coins[i]<=t){
                Take=1+dp[i][t-coins[i]];
            }
            dp[i][t]=min(notTake,Take);
        }
    }
    int ans= dp[n - 1][T];
        if(ans>=1e9)return -1;
        return ans;
}


int coinChange4(vector<int>& coins, int amount) {
    int n=coins.size();
    int T=amount;
   vector<int>prev(T+1,0),curr(T+1,0);   
   
    for(int t=0;t<=T;++t){
        if(t%coins[0]==0){
            prev[t]=t/coins[0];
        }else{
            prev[t]=1e9;
        }
    }
    

    for(int i=1;i<n;++i){
        for(int t=0;t<=T;++t){
            int notTake=0+prev[t];
            int Take=INT_MAX;
            if(coins[i]<=t){
                Take=1+curr[t-coins[i]];
            }
            curr[t]=min(notTake,Take);
        }
        prev=curr;
    }
        int ans= prev[T];
        if(ans>=1e9)return -1;
        return ans;
}


int main(){
    int n, amount;
    cin>>n>>amount;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<coinChange1(coins, amount)<<endl;
    cout<<coinChange2(coins, amount)<<endl;
    cout<<coinChange3(coins, amount)<<endl;
    cout<<coinChange4(coins, amount)<<endl;

    return 0;

}