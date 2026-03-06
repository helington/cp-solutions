#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    for (int i = 1; i < n - 1; i++)
        if (a[i] == -1) a[i] = 0;

    if (a.front() == -1 and a.back() == -1) a.front() = a.back() = 0;
    else if (a.front() == -1) a.front() = a.back();
    else if (a.back() == -1) a.back() = a.front();

    ll ans = 0;
    for (int i = 1; i < n; i++) ans += (a[i] - a[i-1]);
    ans = abs(ans);

    cout << ans << endl;
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