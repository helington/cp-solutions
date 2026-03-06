#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i += 2) m--;

    if (m <= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}