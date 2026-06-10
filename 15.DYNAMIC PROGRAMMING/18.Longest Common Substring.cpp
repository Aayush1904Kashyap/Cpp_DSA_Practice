#include <bits/stdc++.h>
using namespace std;

string longestCommonSubstring(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLen = 0;
    int endPos = 0; // ending index in s1

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];

                if(dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endPos = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return s1.substr(endPos - maxLen, maxLen);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubstring(s1, s2) << endl;
}