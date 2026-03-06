#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl '\n'

const int INF = 4e9;

bool check(set<int> &window, int v, int d) {
    auto it = window.lower_bound(v);

    if (*it - d < v) return false;
    it--;
    if (*it + d > v) return false;

    return true;
}

void solve() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    set<int> window({-INF, INF});
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n and (l == r or check(window, a[r], d))) {
            window.insert(a[r]);
            r++;
        }

        ans += (r - l);
        window.erase(a[l]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
