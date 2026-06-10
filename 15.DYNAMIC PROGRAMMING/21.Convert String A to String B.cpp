#include <bits/stdc++.h>
using namespace std;


int LCS(string s1,string s2){
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



int minDistance(string word1, string word2) {
        int x=LCS(word1, word2);
        return (word1.size()-x) + (word2.size()-x);
}

int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;

    cout<<minDistance(s1,s2)<<endl;

    return 0;
}

/*
any string can be coverted to another string by deleting the characters which are not common in both the strings and inserting the characters which are not common in both the strings.
*/
