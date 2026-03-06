#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"
#define MOD 1000000007

ll dfs1(
    vector<ll> &dp, vector<pair<int, int>> &adj,
    int u=1
    ) {
    if (adj[u].first == 0) return dp[u] = 0;
    if (dp[u] != -1) return dp[u];

    dp[u] = 0;

    dp[u] += (2 + dfs1(dp, adj, adj[u].first));
    dp[u] %= MOD;

    dp[u] += (2 + dfs1(dp, adj, adj[u].second));
    dp[u] %= MOD;

    return dp[u];
}

void dfs2(
    vector<ll> &dp, vector<pair<int, int>> &adj,
    vector<int> &parent,
    int u=1
    ) {
    dp[u] += (1 + dp[parent[u]]);
    dp[u] %= MOD;

    if (adj[u].first != 0) {
        dfs2(dp, adj, parent, adj[u].first);
        dfs2(dp, adj, parent, adj[u].second);
    }
}

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> adj(n+1);
    adj[0] = {1, -1};

    vector<int> parent(n+1, -1);
    parent[1] = 0;

    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        adj[i].first = l; adj[i].second = r;

        if (l==0) continue;

        parent[l]=i; parent[r]=i;
    }

    vector<ll> dp(n+1, -1);
    dfs1(dp, adj);

    dp[0] = 0;

    dfs2(dp, adj, parent);

    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}