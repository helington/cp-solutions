#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const int MOD = 998244353;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);

        sz[u] += sz[v];
        parent[v] = u;
        return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;

    DSU dsu(n);
    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        edges[i] = {u, v, i+1};
    }
    sort(edges.begin(), edges.end(), [&](const tuple<int, int, int> &e1, const tuple<int, int, int> &e2) {
        return get<2>(e1) > get<2>(e2);
    });

    int components = n;
    vector<int> weights;
    for (const auto &edge : edges) {
        auto [u, v, i] = edge;
        u = dsu.find(u), v = dsu.find(v);
        if (u != v) {
            if (components == 2) continue;
            components--;
            dsu.unite(u, v);
        }
        weights.push_back(i);
    }
    sort(weights.begin(), weights.end());

    vector<int> del_weights;
    if (weights.empty()) {
        for (int i = 1; i <= m; i++) del_weights.push_back(i);
    }
    int j = 1;
    for (int i = 0; i < (int)weights.size(); i++) {
        while (j < weights[i]) del_weights.push_back(j++);
        j = weights[i] + 1;
    }

    int ans = 0;
    int curr_base = 2, curr_exp = 1;

    for (auto w : del_weights) {
        while (curr_exp < w) {curr_base = (curr_base * 2) % MOD; curr_exp++;}
        ans = (ans + curr_base) % MOD;
    }

    cout << ans << endl;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}