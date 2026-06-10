#include <bits/stdc++.h>
using namespace std;

// Steps to solve the shortest common supersequence:
// 1. Build a DP table for the LCS of both strings.
// 2. Backtrack from the end to find the common subsequence.
// 3. Add the unmatched characters from both strings.
// 4. Reverse the result to get the final supersequence.

string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len = dp[n][m];
    string ans="";

    int index = len - 1;
    int i = n, j = m;

    while(i > 0 && j > 0) {
        if(str1[i - 1] == str2[j - 1]) {
            ans+=str1[i - 1];
            index--;
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) {
            ans+=str1[i - 1];
            i--;
        }
        else {
            ans+=str2[j - 1];
            j--;
        }
    }

    while(i > 0) {
        ans+=str1[i - 1];
        i--;
    }
    while(j > 0) {
        ans+=str2[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans; 
}

int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;

    cout<<shortestCommonSupersequence(s1,s2)<<endl;

    return 0;
}


/*
supersequence is a sequence which has both the strings as subsequences.

length of the shortest common supersequence of two strings = length of string 1 + length of string 2 - length of longest common subsequence of the two strings.
*/