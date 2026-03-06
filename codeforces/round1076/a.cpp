#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; ll s, x; cin >> n >> s >> x;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll total = accumulate(v.begin(), v.end(), 0ll);

    if (total > s) {cout << "NO" << endl; return;}
    if (total == s) {cout << "YES" << endl; return;}

    if ((s - total) % x == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >>tc; while (tc--) {
        solve();
    }

    return 0;
}