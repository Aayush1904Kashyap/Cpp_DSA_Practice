/*

assume a situation
there is one thief and one bag of capacity W=8. 
There are n=3 items and 
the weight of the ith item is given by wt[i]=[3,4,5]. 
and value of the ith item is given by val[i]=[30,50,60].
The thief can either include the item in the bag or exclude it.
The thief wants to maximize the total value of the items in the bag without exceeding the capacity W.
This is the classic 0/1 Knapsack problem, where we need to determine the maximum

//Greedy approach:
n=3, W=6,wt=[3,2,5], val=[30,40,60]
here greedy approach will be fail because their is no uniformity


//recursion:
1. express in terms of index and weight,f(i,W)
2. explore all possibilities of taking and not taking the current element
3.maximum of both the cases will be our answer



*/

#include <bits/stdc++.h>
using namespace std;

int f(int i, int W, vector<int>& wt, vector<int>& val){
    // try to think base cases as single element array and how it will behave
    if(i==0){
        if(wt[0]<=W) return val[0];
        else return 0;
    }

    int notTake = 0 + f(i-1, W, wt, val);
    int take = INT_MIN;
    if(wt[i]<=W){
        take=val[i]+f(i-1, W-wt[i], wt, val);
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
        if(wt[0]<=W) return val[0];
        else return 0;
    }

    if(dp[i][W]!=-1) return dp[i][W];
    int notTake = 0 + fdp(i-1, W, wt, val, dp);
    int take = INT_MIN;
    if(wt[i]<=W){
        take=val[i]+fdp(i-1, W-wt[i], wt, val, dp);
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
      dp[0][i] = val[0];  
    }
    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            int notTake = 0 + dp[i-1][w];
            int take = INT_MIN;
            if(wt[i]<=w){
                take=val[i]+dp[i-1][w-wt[i]];
            }
            dp[i][w] = max(take, notTake);
        }
    }
    return dp[n-1][W];
}

int knapsack4(int n, int W, vector<int> &wt, vector<int> &val) {
    // single row optimization

    vector<int>prev(W+1, 0);

    for(int i=wt[0];i<=W;i++){
         prev[i] = val[0];
        
    }
    for(int i=1;i<n;i++){
        for(int w=W;w>=0;w--){
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if(wt[i]<=w){
                take=val[i]+prev[w-wt[i]];
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