#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;

    vector<ll> C(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> C[i];
    }

    ll ans = 0;
    ll carry = 0;

    for (ll i = 0; i < N; i++)
    {
        ll cur = C[i];

        if (carry > 0)
        {
            ll space = M - carry;
            ll used = min(cur, space);
            cur -= used;
            carry = 0;
        }

        ans += cur / M;
        cur %= M;

        if (cur > 0)
        {
            ans++;
            carry = cur;
        }
    }

    cout << ans;
    return 0;
}