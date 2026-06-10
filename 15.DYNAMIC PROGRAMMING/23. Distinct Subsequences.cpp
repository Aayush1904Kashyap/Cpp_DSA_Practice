#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string& s1, string& s2) {
    if(j<0) return 1;
    if(i<0) return 0;
    
    if(s1[i]==s2[j]){
        return f(i-1, j-1, s1, s2) + f(i-1, j, s1, s2);
    } else {
        return f(i-1, j, s1, s2);
    }
}

int fdp(int i, int j, string& s1, string& s2,vector<vector<int>>& dp) {
    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j] != -1)return dp[i][j];
    
    if(s1[i]==s2[j]){
       return dp[i][j]= fdp(i-1, j-1, s1, s2,dp) + fdp(i-1, j, s1, s2,dp);
    } else {
        return dp[i][j]= fdp(i-1, j, s1, s2,dp);
    }
}

int numDistinct1(string s, string t) {
       int n=s.size();
       int m=t.size();
        return f(n-1, m-1, s, t); 
}

int numDistinct2(string s, string t) {
       int n=s.size();
       int m=t.size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
        return fdp(n-1, m-1, s, t,dp); 
}

int numDistinct3(string s, string t) {
       int n=s.size();
       int m=t.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       

    for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=0;
        }

 

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               if(s[i-1]==t[j-1]){
                    dp[i][j]= dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j]= dp[i-1][j];
            }
        }
        
}
return dp[n][m];
}

int numDistinct4(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double>prev(m + 1,0),curr(m+1,0);

        prev[0]=curr[0]=1;


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev=curr;
        }
        return (int)prev[m];
    }

    int numDistinct5(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double>prev(m + 1,0);

        prev[0]=1;


        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    prev[j] = prev[j - 1] + prev[j];
                } 
        }
        
    }
    return (int)prev[m];
}

int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;

    cout<<numDistinct1(s1, s2)<<endl;
    cout<<numDistinct2(s1, s2)<<endl;
    cout<<numDistinct3(s1, s2)<<endl;
    cout<<numDistinct4(s1, s2)<<endl;
    cout<<numDistinct5(s1, s2)<<endl;
    return 0;
}