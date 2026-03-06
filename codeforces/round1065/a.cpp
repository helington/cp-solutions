#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    if (n % 2 == 1) cout << 0 << endl;
    else {
        int ans = 0;
        int pairs = n / 2;
        while (pairs >= 0) ans++, pairs -= 2;

        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}