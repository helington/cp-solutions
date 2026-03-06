#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

ll mod_mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll fexp(ll base, ll exp) {
    ll res = 1;
    base %= MOD;

    while (exp) {
        if (exp & 1) res = mod_mul(res,base);
        base = mod_mul(base, base);
        exp >>= 1;
    }

    return res;
}

ll inv(ll a) {
    return fexp(a, MOD - 2);
}

pair<vector<ll>, vector<ll>> precompute(int MAXN) {
    vector<ll> fact(MAXN + 1), invFact(MAXN + 1);

    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = inv(fact[i]);
    }

    return {fact, invFact};
}

ll binomial(ll n, ll k, vector<ll> &fact, vector<ll> &invFact) {
    if (k > n or k < 0) return 0;
    return (fact[n] * invFact[k] % MOD * invFact[n - k] % MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto [fact, invFact] = precompute(1e6+10);

    int tc; cin >> tc; while (tc--) {
        int n, k; cin >> n >> k;

        cout << binomial(n, k, fact, invFact) << endl;
    }

    return 0;
}