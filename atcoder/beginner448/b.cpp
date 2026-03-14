#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    vector<ll> c(m);
    for (auto &it : c) cin >> it;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = a[i] - 1;
        ll curr = min(b[i], c[idx]);
        ans += curr;
        c[idx] -= curr;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}