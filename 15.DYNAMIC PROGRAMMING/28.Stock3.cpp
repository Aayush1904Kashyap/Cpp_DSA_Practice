#include <bits/stdc++.h>
using namespace std;

int f(int i,  int buy,int cap,vector<int>& prices){
    int n=prices.size();
    if(cap==0 || i==n) return 0 ;
    int profit=0;
    if(buy){
        profit=max(-prices[i] + f(i+1,0,cap,prices),
                    0+f(i+1,1,cap,prices));
    }else{
        profit=max(prices[i]+f(i+1,1,cap-1,prices),
                0+f(i+1,0,cap,prices));
    }
    return profit;
}

int maxProfit1(vector<int>& prices) {
    return f(0,1,2,prices);
}

    int fdp(int i, int buy, int cap, vector<int>& prices,
            vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if (cap == 0 || i == n)
            return 0;
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        int profit = 0;
        if (buy) {
            return dp[i][buy][cap] =
                       max(-prices[i] + fdp(i + 1, 0, cap, prices, dp),
                           0 + fdp(i + 1, 1, cap, prices, dp));
        } else {
            return dp[i][buy][cap] =
                       max(prices[i] + fdp(i + 1, 1, cap - 1, prices, dp),
                           0 + fdp(i + 1, 0, cap, prices, dp));
        }
    }

int maxProfit2(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return fdp(0,1,2,prices,dp);
}

int maxProfit3(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

    // for(int i=0;i<n;i++){
    //     for(int buy=0;buy<=1;buy++){
    //         dp[i][buy][0]=0;
    //     }
    // }

    // for(int cap=0;cap<=2;cap++){
    //     for(int buy=0;buy<=1;buy++){
    //         dp[n][buy][cap]=0;
    //     }
    // }

    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                if (buy) {
             dp[i][buy][cap] =
                       max(-prices[i] + dp[i + 1][0][cap],
                           0 + dp[i + 1][1][cap]);
        } else {
             dp[i][buy][cap] =
                       max(prices[i] + dp[i + 1][1][cap-1],
                           0 + dp[i + 1][0][cap]);
        }
            }
        }
    }
    return dp[0][1][2];

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
}