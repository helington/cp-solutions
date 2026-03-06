#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    ll dec = 0;
    ll diff = 8;
    for (int i = 1; i <= n; i++) {
        ll square = i * i;
        ll ans = (square * (square - 1)) / 2;
        if (i >= 3) ans -= dec;

        cout << ans << endl;

        if (i >= 2 ) {
            dec += diff;
            diff += 8;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}