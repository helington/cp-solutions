#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const int INF = 1e9;

int n;

void dfs(
    vector<vector<int>> &adj, vector<int> &dp,
    int &ans, int u=0, int past=-1
    ) {
    int deg = (int) adj[u].size();

    int max_1 = 0, max_2 = 0;

    for (auto v : adj[u]) {
        if (v != past) {
            dfs(adj, dp, ans, v, u);

            if (dp[v] > max_1)
                max_2 = max_1, max_1 = dp[v];
            else if (dp[v] > max_2)
                max_2 = dp[v];
        }
    }

    // pode servir como ponte
    if (deg >= 4)
        dp[u] = max_1 + 1, ans = max(ans, max_1 + max_2 + 1);
    // só pode servir como terminal
    else if (deg == 3)
        dp[u] = 1, ans = max(ans, max_1 + 1);
    else
        dp[u] = 0;
}

void solve() {
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp(n, -1);

    int ans=0;
    dfs(adj, dp, ans);

    cout << max(ans, 1) << endl;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}