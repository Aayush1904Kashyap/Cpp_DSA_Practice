/*
unbounded knapsack means we can take an item multiple times.
the only difference between unbounded knapsack and 0/1 knapsack is in the recursive call for the pick case. 
In 0/1 knapsack, we move to the next item after picking the current item,
while in unbounded knapsack, we stay on the same item to allow for multiple picks of that item.
*/


#include <bits/stdc++.h>
using namespace std;

int f(int i, int W, vector<int>& wt, vector<int>& val){
    // try to think base cases as single element array and how it will behave
    if(i==0){
       return ((int)(W/wt[0])) * val[0];
    }

    int notTake = 0 + f(i-1, W, wt, val);
    int take = INT_MIN;
    if(wt[i]<=W){
        take=val[i]+f(i, W-wt[i], wt, val);
    }
    return max(take, notTake);

    //TC: O(2^n)
    //SC: O(n) for recursion stack
}

int knapsack1(int n, int W, vector<int> &wt, vector<int> &val) {
    // Write your code here.
    return f(n-1, W, wt, val);
}

int fdp(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
        if(i==0){
        return ((int)(W/wt[0])) * val[0];
        
    }

    if(dp[i][W]!=-1) return dp[i][W];
    int notTake = 0 + fdp(i-1, W, wt, val, dp);
    int take = INT_MIN;
    if(wt[i]<=W){
        take=val[i]+fdp(i, W-wt[i], wt, val, dp);
    }
    return dp[i][W] = max(take, notTake);
}

int knapsack2(int n, int W, vector<int> &wt, vector<int> &val) {
    // Write your code here.
    //dp[i][w+1]
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    return fdp(n-1, W, wt, val, dp);
}

int knapsack3(int n, int W, vector<int> &wt, vector<int> &val) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(W+1,0));
    for(int i=wt[0];i<=W;i++){
      dp[0][i] = ((int)(i/wt[0])) * val[0];  
    }
    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            int notTake = 0 + dp[i-1][w];
            int take = INT_MIN;
            if(wt[i]<=w){
                take=val[i]+dp[i][w-wt[i]];
            }
            dp[i][w] = max(take, notTake);
        }
    }
    return dp[n-1][W];
}

int knapsack4(int n, int W, vector<int> &wt, vector<int> &val) {

    vector<int> prev(W+1, 0);

    for(int w=wt[0]; w<=W; w++){
        prev[w] = (w / wt[0]) * val[0];
    }

    for(int i=1; i<n; i++){
        for(int w=0; w<=W; w++){      
            int notTake = prev[w];

            int take = INT_MIN;
            if(wt[i] <= w){
                take = val[i] + prev[w - wt[i]];
            }

            prev[w] = max(take, notTake);
        }
    }

    return prev[W];
}

int main(){
    int n,W;
    cin>>n>>W;
    vector<int> wt(n), val(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    cout<<knapsack1(n,W,wt,val)<<endl;
    cout<<knapsack2(n,W,wt,val)<<endl;
    cout<<knapsack3(n,W,wt,val)<<endl;
    cout<<knapsack4(n,W,wt,val)<<endl;
}