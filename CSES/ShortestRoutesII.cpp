#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

const ll INF = 1e18;

int n;

vector<vector<ll>> floyd_warshall(vector<vector<pair<int, ll>>> &adj) {
    vector<vector<ll>> dist(n, vector<ll>(n, INF));

    for (int u = 0; u < n; u++) {
        dist[u][u] = 0;
        for (auto [v, w] : adj[u])
            dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if ((dist[u][k] != INF) and (dist[k][v] != INF))
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }

    return dist;
}

void solve() {
    int m, q; cin >> n >> m >> q;

    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto dist = floyd_warshall(adj);

    while (q--) {
        int u, v; cin >> u >> v; u--, v--;

        ll ans = dist[u][v];
        if (ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}