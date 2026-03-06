#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    vector<ll> a(n), c(n);
    for (auto &it : a) cin >> it;
    for (auto &it : c) cin >> it;

    vector<ll> dp(n, 0ll);
    for (int i = 0; i < n; i++) dp[i] += c[i];

    for (int i = 1; i < n; i++) {
        ll increment = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i]) increment = max(increment, dp[j]);
        }
        dp[i] += increment;
    }

    ll total = accumulate(c.begin(), c.end(), 0ll);
    ll dincrement = 0;
    for (int i = 0; i < n; i++) dincrement = max(dincrement, dp[i]);

    ll ans = total - dincrement;

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}