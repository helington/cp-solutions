#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    cout << *max_element(a.begin(), a.end()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}