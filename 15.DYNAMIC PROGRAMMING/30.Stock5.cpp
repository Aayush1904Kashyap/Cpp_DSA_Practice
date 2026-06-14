#include <bits/stdc++.h>
using namespace std;

int f(int i,int buy,vector<int>& prices){
    int n=prices.size();
    if(i>=n){
        return 0;
    }

    int profit=0;
    if(buy){
        profit=max(-prices[i]+f(i+1,0,prices),0+f(i+1,1,prices));
    }else{
        profit=max(prices[i]+f(i+2,1,prices),0+f(i+1,0,prices));
    }

    return profit;
}

int maxProfit1(vector<int>& prices) {
    return f(0,1,prices);
}

int fdp(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
    int n=prices.size();
    if(i>=n){
        return 0;
    }
    if(dp[i][buy]!= -1) return dp[i][buy];
    int profit=0;
    if(buy){
        profit=max(-prices[i]+fdp(i+1,0,prices,dp),0+fdp(i+1,1,prices,dp));
    }else{
        profit=max(prices[i]+fdp(i+2,1,prices,dp),0+fdp(i+1,0,prices,dp));
    }

    return dp[i][buy]=profit;
}

int maxProfit2(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return fdp(0,1,prices,dp);
}

int maxProfit3(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));

    for(int i=n-1;i>=0;--i){
        for(int buy=0;buy<=1;++buy){
        int profit=0;
           if(buy){
                profit=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                }else{
                profit=max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
            } 
            dp[i][buy]=profit;
        }
    }
    return dp[0][1];
}

int maxProfit4(vector<int>& prices) {
   vector<int> ahead1(2, 0); // i+1
        vector<int> ahead2(2, 0); // i+2
        vector<int> curr(2, 0);

        for (int i = prices.size() - 1; i >= 0; i--) {

            curr[1] = max(-prices[i] + ahead1[0], ahead1[1]);

            curr[0] = max(prices[i] + ahead2[1], ahead1[0]);

            ahead2 = ahead1;
            ahead1 = curr;
        }

        return ahead1[1];
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<maxProfit1(arr)<<endl;
    cout<<maxProfit2(arr)<<endl;
    cout<<maxProfit3(arr)<<endl;
    cout<<maxProfit4(arr)<<endl;
}