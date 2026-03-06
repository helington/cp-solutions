#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const ll MOD = 1e9 + 7;

ll mod_mul(ll a, ll b) { return (a * b) % MOD; }
ll fexp(ll base, ll exp) {
    ll ans = 1;

    while (exp) {
        if (exp & 1) ans = mod_mul(ans, base);
        base = mod_mul(base, base);
        exp >>= 1;
    }

    return ans;
}
ll inv(ll a) { return fexp(a, MOD - 2); }

pair<vector<ll>, vector<ll>> precompute(int MAXN) {
    vector<ll> fact(MAXN), invFact(MAXN);
    fact[0] = fact[1] = 1;

    for (int i = 1; i < MAXN; i++) {
        fact[i] = mod_mul(fact[i - 1], i);
        invFact[i] = inv(fact[i]);
    }

    return {fact, invFact};
}

void solve() {
    ll n; cin >> n;

    if (n % 2 != 0) cout << 0 << endl;
    else {
        int MAXN = n + 10;
        n /= 2;
        auto [fact, invFact] = precompute(MAXN);
        ll ans = ((fact[2 * n] * invFact[n + 1]) % MOD * invFact[n]) % MOD;

        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}