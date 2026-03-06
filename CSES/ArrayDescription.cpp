#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

int n, m;

ll mod_add(ll a, ll b) {
    return (a + b) % MOD;
}

ll total_ways(vector<ll> &x) {
    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));

    if (x[0] == 0) for (int j = 1; j <= m; j++) dp[0][j] = 1;
    else dp[0][x[0]] = 1;

    for (int i = 1; i < n; i++) {
        if (x[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = mod_add(dp[i][j], dp[i-1][j]);
                if (j > 0) dp[i][j] = mod_add(dp[i][j], dp[i-1][j-1]);
                if (j < m) dp[i][j] = mod_add(dp[i][j], dp[i-1][j+1]);
            }
        }
        else {
            auto j = x[i];
            dp[i][j] = mod_add(dp[i][j], dp[i-1][j]);
            if (j > 0) dp[i][j] = mod_add(dp[i][j], dp[i-1][j-1]);
            if (j < m) dp[i][j] = mod_add(dp[i][j], dp[i-1][j+1]);
        }
    }

    ll ans = 0;
    for (int i = 0; i <= m; i++) ans = mod_add(ans, dp[n-1][i]);

    return ans;
}

void solve() {
    cin >> n >> m;

    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << total_ways(x) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}