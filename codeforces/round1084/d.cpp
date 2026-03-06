#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n, x, y; cin >> n >> x >> y;

    vector<int> p(n);
    for (auto &it : p) cin >> it;

    vector<int> middle; int idx_m = -1;

    vector<int> ans1;

    for (int i = 0; i < x; i++) {
        ans1.push_back(p[i]);
    }
    for (int i = x; i < y; i++) {
        middle.push_back(p[i]);
        if (idx_m == -1 or middle.back() < middle[idx_m]) idx_m = middle.size()-1;
    }
    for (int i = y; i < n; i++) {
        ans1.push_back(p[i]);
    }

    idx_m = max(idx_m, 0);

    vector<int> ans2;
    for (int i = idx_m; i < middle.size(); i++) ans2.push_back(middle[i]);
    for (int i = 0; i < idx_m; i++) ans2.push_back(middle[i]);

    int i = 0;
    for (; i < ans1.size(); i++) {
        if (!ans2.empty() and ans1[i] > ans2[0]) break;
        cout << ans1[i] << " ";
    }
    for (int j = 0; j < ans2.size(); j++) cout << ans2[j] << " ";
    for (; i < ans1.size(); i++) cout << ans1[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}