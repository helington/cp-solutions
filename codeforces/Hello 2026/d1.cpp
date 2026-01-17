#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

int n; int m;

pair<vector<int>, vector<int>> bfs(vector<vector<int>> &adj) {
    vector<int> dist(n, -1);
    dist[0] = 0;

    vector<int> parent(n);
    parent[0] = -1;

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                parent[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return {dist, parent};
}

void solve() {
    cin >> n; m = n-1;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> color(n, false);

    auto [dist, parent] = bfs(adj);

    vector<int> available_nodes(n);
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) available_nodes[j]++;
    }

    int operations = 0;
    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            operations++;
            color[i] = true;
            set<int> useds; useds.insert(i);
            map<int, int> distances; distances[dist[i]] = i;

            for (int j = i+1; j < n; j++) {
                if (!color[j] and !useds.count(j) and !useds.count(parent[j])) {
                    if (distances.count(dist[j])) {
                        if (available_nodes[distances[dist[j]]] > available_nodes[j]) continue;
                        color[distances[dist[j]]] = false;
                        useds.erase(distances[dist[j]]);
                    }

                    color[j] = true;
                    useds.insert(j); useds.insert(parent[j]);
                    distances[dist[j]] = j;
                }
            }
            for (auto j : useds) {
                for (auto k : adj[j]) available_nodes[k]--;
            }
        }
    }

    cout << operations << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}