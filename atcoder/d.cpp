#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, q; cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> pref(n+1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i-1];

    while (q--) {
        int op; cin >> op;

        if (op == 1) {
            int x; cin >> x;

            ll val1 = pref[x] - pref[x-1];
            ll val2 = pref[x + 1] - pref[x];

            pref[x] = pref[x] - val1 + val2;
        }
        else {
            int l, r; cin >> l >> r;

            cout << pref[r] - pref[l-1] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}