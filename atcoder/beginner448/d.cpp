#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void dfs(
    vector<vector<int>> &adj, vector<int> &a,
    vector<bool> &flags, multiset<int> &vis,
    bool flag=false, int u=0, int past=-1
    ) {
    if (vis.count(a[u])) flag = true;
    if (flag) flags[u] = true;
    vis.insert(a[u]);

    for (auto v : adj[u]) {
        if (v == past) continue;
        dfs(adj, a, flags, vis, flag, v, u);
    }

    vis.erase(vis.find(a[u]));
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> flag(n, false);
    multiset<int> vis;
    dfs(adj, a, flag, vis);

    for (auto u : flag)
        cout << (u ? "Yes" : "No") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}