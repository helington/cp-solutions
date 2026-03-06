#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);
    int xor_total = 0;
    for (auto &it : a) cin >> it, xor_total ^= it;
    for (auto &it : b) cin >> it, xor_total ^= it;

    if (!xor_total) cout << "Tie" << endl;
    else {
        bool Mai = true;
        for (int i = n-1; i >= 0; i--) {
            if (a[i] != b[i]) {
                if (i % 2 == 0) Mai = false;
                break;
            }
        }
        if (Mai) cout << "Mai" << endl;
        else cout << "Ajisai" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}