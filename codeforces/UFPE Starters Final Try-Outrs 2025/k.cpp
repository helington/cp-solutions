#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n, m; cin >> n >> m;

    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(m+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') dp[i+1][j+1] = {0, 0};
            else dp[i+1][j+1] = {-1, -1};
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (dp[1][i].first != -1) continue;
        dp[1][i] = {1, dp[1][i-1].second + 1};
        ans = max(ans, dp[1][i].second);
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i][1].first != -1) continue;
        dp[i][1] = {dp[i-1][1].first + 1, 1};
        ans = max(ans, dp[i][1].first);
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (dp[i][j].first != -1) continue;
            int bound = dp[i-1][j].first;
            int min_w = dp[i][j-1].second+1;
            dp[i][j] = {bound+1, min_w};

            for (int k = i, h=1; k >= i-bound; k--, h++) {
                min_w = min(min_w, dp[k][j].second);
                int curr = min_w * h;
                ans = max(ans, curr);
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}