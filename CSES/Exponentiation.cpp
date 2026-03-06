#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

const ll MOD = 1e9 + 7;

ll fexp(ll base, ll exp) {
    ll ans = 1;

    while (exp) {
        if (exp & 1) ans = (ans * base) % MOD;
        exp >>= 1;
        base = (base * base) % MOD;
    }

    return ans;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        ll a, b; cin >> a >> b;
        cout << fexp(a, b) << endl;
    }
}