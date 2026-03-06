#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"



void solve() {
    int n; cin >> n;

    vector<int> p(n);
    for (auto &it : p) cin >> it;

    int idx=0;
    for (int i = 0; i < n; i++) {
        if (p[i] == n) {idx = i; break;}
    }
    swap(p[0], p[idx]);

    for (auto &it : p) cout << it << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}