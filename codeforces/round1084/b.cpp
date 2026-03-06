#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it: a) cin >> it;

    auto sorted = a;
    sort(sorted.begin(), sorted.end());

    if (sorted == a) cout << n << endl;
    else cout << 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}