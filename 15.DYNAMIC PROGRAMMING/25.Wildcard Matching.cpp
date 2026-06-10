#include <bits/stdc++.h>
using namespace std;
 
bool f(int i, int j, const string& s, const string& p) {
    if (i < 0 && j < 0) return true;
    if (j < 0) return false;
    if (i < 0) {
        for (int k = 0; k <= j; k++)
            if (p[k] != '*') return false;
        return true;
    }
 
    if (p[j] == '*') {
        return f(i, j - 1, s, p) || f(i - 1, j, s, p);
    } else if (p[j] == '?' || p[j] == s[i]) {
        return f(i - 1, j - 1, s, p);
    } else {
        return false;
    }
}
 
bool isMatch1(string s, string p) {
    int n = s.size(), m = p.size();
    return f(n - 1, m - 1, s, p);
}
 
bool fdp(int i, int j, const string& s, const string& p, vector<vector<int>>& dp) {
    if (i < 0 && j < 0) return true;
    if (j < 0) return false;
    if (i < 0) {
        for (int k = 0; k <= j; k++)
            if (p[k] != '*') return false;
        return true;
    }
 
    if (dp[i][j] != -1) return dp[i][j];
 
    bool res;
    if (p[j] == '*') {
        res = fdp(i, j - 1, s, p, dp) || fdp(i - 1, j, s, p, dp);
    } else if (p[j] == '?' || p[j] == s[i]) {
        res = fdp(i - 1, j - 1, s, p, dp);
    } else {
        res = false;
    }
 
    return dp[i][j] = res;
}
 
bool isMatch2(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fdp(n - 1, m - 1, s, p, dp);
}
 
bool isMatch3(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
 
    dp[0][0] = true;
 
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = false;
            }
        }
    }
 
    return dp[n][m];
}
 
bool isMatch4(string s, string p) {
    int n = s.size(), m = p.size();
 
    vector<bool> prev(m + 1, false), curr(m + 1, false);
 
    prev[0] = true;
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') prev[j] = prev[j - 1];
    }
 
    for (int i = 1; i <= n; i++) {
        curr[0] = false;
 
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                curr[j] = curr[j - 1] || prev[j];
            } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                curr[j] = prev[j - 1];
            } else {
                curr[j] = false;
            }
        }
 
        prev = curr;
    }
 
    return prev[m];
}
bool isMatch5(string s, string p) {
    int n = s.size(), m = p.size();

    vector<bool> dp(m + 1, false);

    dp[0] = true;
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') dp[j] = dp[j - 1];
    }

    for (int i = 1; i <= n; i++) {
        bool diag = dp[0];  
        dp[0] = false;

        for (int j = 1; j <= m; j++) {
            bool temp = dp[j];  
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 1] || dp[j];
            } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                dp[j] = diag;
            } else {
                dp[j] = false;
            }
            diag = temp;
        }
    }

    return dp[m];
}

int main() {
    string s, p;
    cin >> s >> p;

    cout << boolalpha;
    cout << isMatch1(s, p) << endl;
    cout << isMatch2(s, p) << endl;
    cout << isMatch3(s, p) << endl;
    cout << isMatch4(s, p) << endl;
    cout << isMatch5(s, p) << endl;

    return 0;
}