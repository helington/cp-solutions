#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int x, y; cin >> x >> y;

    if (y < 0) x -= 4 * (-y);
    else if (y > 0) x -= 2 * y;

    if (x < 0 or x % 3 != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}