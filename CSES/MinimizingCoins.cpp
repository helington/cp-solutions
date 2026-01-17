#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl '\n'

int n;

int best(vector<int> &dp, vector<int> &coins, int x) {
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];

    dp[x] = INT32_MAX;
    for (int i = 0; i < n and x - coins[i] >= 0; i++) {
        int current = best(dp, coins, x - coins[i]) + 1;
        dp[x] = min(dp[x], current);
    }

    return dp[x];
}

void solve() {
    int x; cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());

    vector<int> dp(x + 1, -1);

    int ans = best(dp, coins, x);

    if (ans == INT32_MAX) cout << -1;
    else cout << ans;
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}