#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

int leafs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dp, int u = 0) {
    vis[u] = true;

    dp[u] = 0;
    for (auto v : adj[u]) {
        if (!vis[v]) dp[u] += leafs(adj, vis, dp, v);
    }

    if (dp[u] == 0) dp[u] = 1;
    return dp[u];
}

void solve() {
    int n; cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    vector<int> dp(n, -1);

    leafs(adj, vis, dp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while(tc--) {
        solve();
    }

    return 0;
}