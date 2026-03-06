#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    map<int, int> dp;

    for (auto &it : a) {
        int curr;
        curr = dp[it-1] + 1;
        dp[it] = max(dp[it], curr);
    }

    int ans = 0;
    for (auto [key, value] : dp) ans = max(ans, value);

    cout << ans << endl;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}