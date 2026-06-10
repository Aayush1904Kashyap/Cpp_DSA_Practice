#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,string& s1,string& s2){

    if(i<0)return j+1;
    if(j<0)return i+1;

    if(s1[i]==s2[j]){
        return 0+ f(i-1,j-1,s1,s2);
    }else{
        int insert=1+f(i,j-1,s1,s2);
        int del=1+f(i-1,j,s1,s2);
        int replace= 1+f(i-1,j-1,s1,s2);

        return min(insert,min(del,replace));
    }
}

int minDistance1(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return f(n-1,m-1,word1,word2);
}

int fdp(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){

    if(i<0)return j+1;
    if(j<0)return i+1;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i]==s2[j]){
        return dp[i][j]= 0 + fdp(i-1,j-1,s1,s2,dp);
    }else{
        int insert=1+fdp(i,j-1,s1,s2,dp);
        int del=1+fdp(i-1,j,s1,s2,dp);
        int replace= 1+fdp(i-1,j-1,s1,s2,dp);

        return dp[i][j]= min(insert,min(del,replace));
    }
}

int minDistance2(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fdp(n-1,m-1,word1,word2,dp);
}

int minDistance3(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<=m;++j){
            dp[0][j]=j;
        }

        for(int i=0;i<=n;++i){
            dp[i][0]=i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }else{
                    int insert=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int replace= 1+dp[i-1][j-1];
                    dp[i][j]= min(insert,min(del,replace));
                }
            }
        }
        return dp[n][m];
}


    int minDistance4(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = i;

            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    int insert = 1 + curr[j - 1];
                    int del = 1 + prev[j];
                    int replace = 1 + prev[j - 1];

                    curr[j] = min({insert, del, replace});
                }
            }

            prev = curr;
        }

        return prev[m];
    }


int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;

    cout<<minDistance1(s1,s2)<<endl;
    cout<<minDistance2(s1,s2)<<endl;
    cout<<minDistance3(s1,s2)<<endl;
    cout<<minDistance4(s1,s2)<<endl;

    return 0;
}


