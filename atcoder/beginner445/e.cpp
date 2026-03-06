#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const ll MOD = 998244353;
const int MAXN = 1e7;

ll mod_mul(ll a, ll b) {
    return (a % MOD * b % MOD) % MOD;
}

ll fexp(ll base, ll exp) {
    ll res = 1;
    base %= MOD;

    while (exp) {
        if (exp & 1) res = mod_mul(res, base);
        base = mod_mul(base, base);
        exp >>= 1;
    }

    return res;
}

ll inv (ll a) {
    return fexp(a, MOD - 2);
}

vector<int> sieve() {
    vector<int> spf(MAXN+1, -1);

    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == -1) {
            spf[i] = i;
            for (int j = 2 * i; j <= MAXN; j += i) {
                spf[j] = i;
            }
        }
    }

    return spf;
}

void solve(vector<int> &spf) {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    map<int, int> mp1, mp2;

    for (int i = 0; i < n; i++) {
        int x = a[i];

        while (x > 1) {
            int p = spf[x], cnt = 0;

            while (x % p == 0) x /= p, cnt++;

            if (cnt > mp1[p])
                mp2[p] = mp1[p], mp1[p] = cnt;
            else if (cnt > mp2[p])
                mp2[p] = cnt;

        }
    }

    ll max_lcm = 1;
    for (auto &[p, cnt] : mp1)
        max_lcm = (max_lcm * fexp(p, cnt)) % MOD;

    for (auto &it : a) {
        ll ans = max_lcm;

        int x = it;
        while (x > 1) {
            int p = spf[x], cnt = 0;
            while (x % p == 0) x /= p, cnt++;

            if (cnt == mp1[p]) {
                ll diff = mp1[p] - mp2[p];
                ans = (ans * inv(fexp(p, diff))) % MOD;
            }
        }

        cout << ans << " ";
    }

    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto spf = sieve();

    int tc; cin >> tc; while(tc--) {
        solve(spf);
    }

    return 0;
}