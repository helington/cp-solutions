#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

int n, m, l, s, t;

vector<bool> bfs(vector<vector<pair<int, int>>> &adj, int b) {
    vector<bool> flag(n, false);

    queue<tuple<int, int, int>> q;
    q.push({b, 0, 0});

    while (!q.empty()) {
        auto [u, u_w, tranverses] = q.front(); q.pop();

        if (tranverses >= l) continue;

        for (auto [v, w] : adj[u]) {
            int current_w = u_w + w;
            if (tranverses + 1 == l and current_w >= s and current_w <= t) flag[v] = true;
            q.push({v, current_w, tranverses + 1});
        }
    }

    return flag;
}

void solve() {
    cin >> n >> m >> l >> s >> t;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        adj[u].push_back({v, w});
    }

    auto flag = bfs(adj, 0);

    for (int i = 0; i < n; i++) {
        if (flag[i]) cout << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}