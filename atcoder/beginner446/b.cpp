#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n, m; cin >> n >> m;

    vector<bool> used(m+1, false);

    vector<vector<int>> x(n);
    for (auto &row : x) {
        int l; cin >> l;
        row.resize(l);
        for (auto &it : row) cin >> it;
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto &it : x[i]) {
            if (!used[it]) { ans[i] = it; used[it] = true; break; }
        }
    }

    for (auto &it : ans) cout << it << endl;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}