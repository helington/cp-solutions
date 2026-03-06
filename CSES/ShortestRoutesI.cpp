#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

const ll INF = 1e18;

int n;

vector<ll> dijkstra(vector<vector<pair<int, ll>>> &adj, int start=0) {
    vector<ll> dist(n, INF);
    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    >pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

void solve() {
    int m; cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back({v, w});
    }

    auto ans = dijkstra(adj);

    for (const auto &d : ans) cout << d << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}