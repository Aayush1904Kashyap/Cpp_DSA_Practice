#include <bits/stdc++.h>
using namespace std;

int f(int i,int buy,int fee,vector<int>& prices){
    int n=prices.size();
    if(i==n){
        return 0;
    }

    int profit=0;
    if(buy){
        profit=max(-prices[i]+f(i+1,0,fee,prices),0+f(i+1,1,fee,prices));
    }else{
        profit=max(prices[i]-fee+f(i+1,1, fee,prices),0+f(i+1,0,fee,prices));
    }

    return profit;
}

int maxProfit1(vector<int>& prices,int fee) {
    return f(0,1,fee,prices);
}

int fdp(int i,int buy,vector<int>& prices,int fee,vector<vector<int>>& dp){
    int n=prices.size();
    if(i==n){
        return 0;
    }
    if(dp[i][buy]!= -1) return dp[i][buy];
    int profit=0;
    if(buy){
        profit=max(-prices[i]+fdp(i+1,0,prices,fee,dp),0+fdp(i+1,1,prices,fee,dp));
    }else{
        profit=max(prices[i]-fee+fdp(i+1,1,prices,fee,dp),0+fdp(i+1,0,prices,fee,dp));
    }

    return dp[i][buy]=profit;
}

int maxProfit2(vector<int>& prices,int fee) {
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return fdp(0,1,prices,fee,dp);
}

int maxProfit3(vector<int>& prices,int fee) {
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    dp[n][0]=dp[n][1]=0;

    for(int i=n-1;i>=0;--i){
        for(int buy=0;buy<=1;++buy){
        int profit=0;
           if(buy){
                profit=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                }else{
                profit=max(prices[i]-fee+dp[i+1][1],0+dp[i+1][0]);
            } 
            dp[i][buy]=profit;
        }
    }
    return dp[0][1];
}

int maxProfit4(vector<int>& prices,int fee) {
    int n=prices.size();
    vector<int>ahead(2,0),curr(2,0);
    ahead[0]=ahead[1]=0;

    for(int i=n-1;i>=0;--i){
        for(int buy=0;buy<=1;++buy){
        int profit=0;
           if(buy){
                profit=max(-prices[i]+ahead[0],0+ahead[1]);
                }else{
                profit=max(prices[i]-fee+ahead[1],0+ahead[0]);
            } 
            curr[buy]=profit;
        }
        ahead=curr;
    }
    return ahead[1];
}

int main(){
    int n,fee;
    cin>>n>>fee;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

  
    cout<<maxProfit2(arr,fee)<<endl;
    cout<<maxProfit3(arr,fee)<<endl;
    cout<<maxProfit4(arr,fee)<<endl;
}