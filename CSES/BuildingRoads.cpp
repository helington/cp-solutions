#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

struct DSU {
    vector<int> parent, sz;

    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);

        sz[u] += sz[v];
        parent[v] = parent[u];
        return true;
    }
};

void solve () {
    int n, m; cin >> n >> m;

    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        dsu.unite(u, v);
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i < n; i++) {
        if (dsu.unite(i, i-1)) ans.push_back({i, i-1});
    }

    cout << ans.size() << endl;
    for (auto [u, v] : ans) cout << u+1 << " " << v+1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}