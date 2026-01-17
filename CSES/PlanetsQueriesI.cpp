#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, q; cin >> n >> q;

    vector<vector<int>> adj(n);

    for (int u = 0; u < n; u++) {
        int v; cin >> v; v--;
        adj[u].push_back(v);
    }

    while (q--) {
        int u; cin >> u; u--;
        int k; cin >> k;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}