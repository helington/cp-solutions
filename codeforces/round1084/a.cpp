#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;
    int max_value = *max_element(a.begin(), a.end());

    int ans = 0;
    for (auto &it : a) {
        if (it == max_value) ans++;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}