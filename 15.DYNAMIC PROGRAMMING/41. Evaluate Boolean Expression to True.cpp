#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1000000007;

ll f(int i, int j, int isTrue, string& exp,
     vector<vector<vector<ll>>>& dp) {

    if (i > j) return 0;

    if (i == j) {
        if (isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    ll ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2) {

        ll lT = f(i, ind - 1, 1, exp, dp);
        ll lF = f(i, ind - 1, 0, exp, dp);
        ll rT = f(ind + 1, j, 1, exp, dp);
        ll rF = f(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&') {
            if (isTrue) {
                ways = (ways + (lT * rT) % mod) % mod;
            } else {
                ways = (ways + (lT * rF) % mod
                             + (lF * rT) % mod
                             + (lF * rF) % mod) % mod;
            }
        }

        else if (exp[ind] == '|') {
            if (isTrue) {
                ways = (ways + (lT * rT) % mod
                             + (lT * rF) % mod
                             + (lF * rT) % mod) % mod;
            } else {
                ways = (ways + (lF * rF) % mod) % mod;
            }
        }

        else if (exp[ind] == '^') {
            if (isTrue) {
                ways = (ways + (lT * rF) % mod
                             + (lF * rT) % mod) % mod;
            } else {
                ways = (ways + (lT * rT) % mod
                             + (lF * rF) % mod) % mod;
            }
        }
    }

    return dp[i][j][isTrue] = ways;
}

int parseBoolExpr(string& expression) {
    int n = expression.size();

    vector<vector<vector<ll>>> dp(
        n, vector<vector<ll>>(n, vector<ll>(2, -1))
    );

    return f(0, n - 1, 1, expression, dp);
}

int main() {
    string expression;
    cin >> expression;

    cout << parseBoolExpr(expression) << endl;

    return 0;
}