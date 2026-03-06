#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, q; cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) a[i] = max(a[i], b[i]);

    for (int i = 0; i < n - 1; i++) a[i] = max(a[i], a[i + 1]);
    for (int i = n - 2; i >= 0; i--) a[i] = max(a[i], a[i + 1]);

    vector<ll> pref(n+1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];

    while (q--) {
        int l, r; cin >> l >> r;

        cout << pref[r] - pref[l - 1] << " ";
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >>tc; while (tc--) {
        solve();
    }

    return 0;
}