#include <bits/stdc++.h>
using namespace std;

int f(int i,int target,vector<int>& coins){

    if(i==0){
        return (target%coins[0]==0) ? 1 : 0;
    }
    int notTake=f(i-1,target,coins);
    int take=0;
    if(coins[i]<=target){
        take=f(i,target-coins[i],coins);
    }
    return take + notTake;

   
}

int change1(int amount, vector<int>& coins) {
    int n=coins.size();    
    int ans= f(n-1,amount,coins);
    if(ans>=1e9)return 0;
    return ans;
}


int fdp(int i, int target, vector<int>& coins, vector<vector<int>>& dp) {

        if (i == 0) {
            return (target % coins[0] == 0);
        }

        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = fdp(i - 1, target, coins, dp);

        int take = 0;
        if (coins[i] <= target) {
            take = fdp(i, target - coins[i], coins, dp);
        }

        return dp[i][target] = take + notTake;
    }

    int change2(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return fdp(n - 1, amount, coins, dp);
    }

int change3(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                dp[0][target] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= amount; target++) {

                int notTake = dp[i - 1][target];

                int take = 0;
                if (coins[i] <= target) {
                    take = dp[i][target - coins[i]];
                }

                dp[i][target] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }

     int change4(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int> prev(amount + 1, 0);

        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                prev[target] = 1;
        }

        for (int i = 1; i < n; i++) {

            vector<int> cur(amount + 1, 0);

            for (int target = 0; target <= amount; target++) {

                int notTake = prev[target];

                int take = 0;
                if (coins[i] <= target) {
                    take = cur[target - coins[i]];
                }

                cur[target] = take + notTake;
            }

            prev = cur;
        }

        return prev[amount];
    }


int main(){
    int n, amount;
    cin>>n>>amount;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<change1( amount,coins)<<endl;
    cout<<change2( amount,coins)<<endl;
    cout<<change3( amount,coins)<<endl;
    cout<<change4( amount,coins)<<endl;

    return 0;
}