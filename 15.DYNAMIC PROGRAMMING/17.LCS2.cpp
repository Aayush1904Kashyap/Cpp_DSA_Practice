#include<bits/stdc++.h>
using namespace std;

string LCS3(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len = dp[n][m];
    string ans(len, '$');

    int index = len - 1;
    int i = n, j = m;

    while(i > 0 && j > 0) {
        if(s1[i - 1] == s2[j - 1]) {
            ans[index] = s1[i - 1];
            index--;
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string lcs = LCS3(s1, s2);

    for(char c : lcs) {
        cout << c;
    }
    cout << endl;

    return 0;
}

