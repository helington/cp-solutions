#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int p, q, x, y; cin >> p >> q;
    cin >> x >> y;

    if (x >= p and x < p + 100 and y >= q and y < q + 100) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}