/*NOT OPTIMISED ONE*/



#include <bits/stdc++.h>
using namespace std;

    const int MOD = 1e9 + 7;

    long long f(int n, int l, int r, int pos, int prev2, int prev1,
                vector<vector<vector<long long>>>& dp) {

        if (pos == n)
            return 1;

        if (dp[pos][prev2 - l][prev1 - l] != -1)
            return dp[pos][prev2 - l][prev1 - l];

        long long ways = 0;

        for (int x = l; x <= r; x++) {

            if (x == prev1)
                continue;

            if (prev2 < prev1 && prev1 < x)
                continue;

            if (prev2 > prev1 && prev1 > x)
                continue;

            ways = (ways + f(n, l, r, pos + 1, prev1, x, dp)) % MOD;
        }

        return dp[pos][prev2 - l][prev1 - l] = ways;
    }

    int zigZagArrays(int n, int l, int r) {

        if (n == 1)
            return (r - l + 1);

        int k = r - l + 1;

        vector<vector<vector<long long>>> dp(
            n + 1, vector<vector<long long>>(k, vector<long long>(k, -1)));

        long long ans = 0;

        for (int first = l; first <= r; first++) {
            for (int second = l; second <= r; second++) {

                if (first == second)
                    continue;

                ans = (ans + f(n, l, r, 2, first, second, dp)) % MOD;
            }
        }

        return ans;
    }

    int zigZagArrays(int n, int l, int r){

    }

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    cout << zigZagArrays(n, l, r) << endl;

    return 0;
}