#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;

    int y = 0;
    for (auto &c : s) {
        if (c == 'Y') y++;
    }

    if (y > 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}