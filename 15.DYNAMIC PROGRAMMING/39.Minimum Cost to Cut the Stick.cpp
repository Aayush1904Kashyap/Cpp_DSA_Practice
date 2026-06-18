#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<int>& cuts){
    if(i>j) return 0;
    int mini=INT_MAX;
    for(int ind=i;ind<=j;ind++){
        int cost=cuts[j+1]-cuts[i-1] + f(i,ind-1,cuts)+f(ind+1,j,cuts);
        mini=min(mini,cost);
    }
    return mini;
}

int minCost0(int n, vector<int>& cuts) {
    int m=cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    return f(1,m,cuts);
}

int minCost(int n, vector<int>& cuts) {
    int m=cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());

    vector<vector<int>> dp(m+2,vector<int>(m+2,0));

    for(int i=m;i>0;--i){
        for(int j=1;j<=m;j++){
            if(i>j)continue;
            int mini=INT_MAX;
            for(int ind=i;ind<=j;ind++){
                int cost=cuts[j+1]-cuts[i-1] + dp[i][ind-1]+dp[ind+1][j];
                mini=min(mini,cost);
    }
        dp[i][j]= mini;
        }
    }

    return dp[1][m];
}

int main() {
    int n;
    cin >> n;

    int m;          // number of cuts
    cin >> m;

    vector<int> cuts(m);
    for (int i = 0; i < m; i++) {
        cin >> cuts[i];
    }

    // cout <<  minCost0(n, cuts) << endl;
    cout <<  minCost(n, cuts) << endl;

    return 0;
}