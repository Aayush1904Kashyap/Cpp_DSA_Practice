#include <bits/stdc++.h>
using namespace std;

int f(int i, int trans, int cap ,vector<int>& prices){
    int n=prices.size();
    if(trans == 2*cap || i==n) return 0 ;
    int profit=0;
    if(trans%2==0){
       return max(-prices[i] + f(i+1,trans+1,cap,prices),
                    0+f(i+1,trans,cap,prices));
    }else{
        return max(prices[i]+f(i+1,trans+1,cap,prices),
                0+f(i+1,trans,cap,prices));
    }
    
}

int maxProfit0(vector<int>& prices,int k){
    return f(0,0,k,prices);
}


int maxProfit1(vector<int>& prices,int k) {
int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int trans = 2 * k - 1; trans >= 0; trans--) {

                // even → buy
                if (trans % 2 == 0) {
                    dp[i][trans] =
                        max(-prices[i] + dp[i + 1][trans + 1],
                            dp[i + 1][trans]);
                }

                // odd → sell
                else {
                    dp[i][trans] =
                        max(prices[i] + dp[i + 1][trans + 1],
                            dp[i + 1][trans]);
                }
            }
        }

        return dp[0][0];

}

int maxProfit2( vector<int>& prices,int k) {
        int n = prices.size();

        vector<int> ahead(2 * k + 1, 0), curr(2 * k + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int trans = 2 * k - 1; trans >= 0; trans--) {

                if (trans % 2 == 0) {
                    curr[trans] =
                        max(-prices[i] + ahead[trans + 1],
                            ahead[trans]);
                } else {
                    curr[trans] =
                        max(prices[i] + ahead[trans + 1],
                            ahead[trans]);
                }
            }
            ahead = curr;
        }

        return ahead[0];
    }

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<maxProfit2(arr,k)<<endl;
}