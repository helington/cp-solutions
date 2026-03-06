#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    bool flag = false;
    int parity = (a[0] % 2);
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 != parity) { flag = true; break; }
    }

    if (flag) sort (a.begin(), a.end());

    for (auto &it : a) cout << it << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}