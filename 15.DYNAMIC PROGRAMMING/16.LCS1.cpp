#include <bits/stdc++.h>
using namespace std;

int f(int i,int j, string& s1, string& s2){

    if(i<0 || j<0) return 0;

    if(s1[i]==s2[j]){
        return 1+f(i-1, j-1, s1, s2);
    }else{
        return 0+max(f(i-1, j,s1,s2), f(i,j-1,s1,s2));
    }
}



int fdp(int i,int j, string& s1, string& s2, vector<vector<int>>& dp){
    if(i<0 || j<0) return 0;

    if(s1[i]==s2[j]){
        dp[i][j]= 1+fdp(i-1, j-1, s1, s2,dp);
    }else{
        dp[i][j]= 0+max(fdp(i-1, j,s1,s2,dp), fdp(i,j-1,s1,s2,dp));
    }
    return dp[i][j];
}

int fdp2(int i,int j, string& s1, string& s2, vector<vector<int>>& dp){
    if(i==0 || j==0) return 0;

    if(s1[i-1]==s2[j-1]){
        dp[i][j]= 1+fdp2(i-1, j-1, s1, s2,dp);
    }else{
        dp[i][j]= 0+max(fdp2(i-1, j,s1,s2,dp), fdp2(i,j-1,s1,s2,dp));
    }
    return dp[i][j];
}


int LCS1(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
    return f(n-1,m-1,s1,s2);

}

int LCS2(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fdp(n-1, m-1, s1, s2, dp);
}

int LCS2_1(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return fdp2(n, m, s1, s2, dp);
}

int LCS3(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
            }else{
                dp[i][j]= 0+max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int LCS4(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    
    vector<int> prev(m+1,0), curr(m+1,0);
    


    for(int j=0;j<=m;j++){
        prev[j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]= 1+prev[j-1];
            }else{
                curr[j]= 0+max(prev[j], curr[j-1]);
            }
        }
        prev=curr;
    }

    return prev[m];
}


int main(){
    string s1,s2;
    cin>>s1>>s2;

    cout<<LCS1(s1,s2)<<endl;
    cout<<LCS2(s1,s2)<<endl;
    cout<<LCS2_1(s1,s2)<<endl;
    cout<<LCS3(s1,s2)<<endl;
    cout<<LCS4(s1,s2)<<endl;

    return 0;
}