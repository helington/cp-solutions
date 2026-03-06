#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll INF = 1e18;

ll checker(ll m) {
    ll y = m;
    ll dy = 0;

    while (m) {
        dy += m % 10;
        m /= 10;
    }

    return y - dy;
}

void solve() {
    ll x; cin >> x;

    if (x % 9 == 0) {
        ll l = x+1, r = INF;
        bool possible = false;

        while (l <= r) {
            ll m = l + (r-l)/2;

            ll check = checker(m);

            if (check == x) {
                possible = true;
                break;
            }

            if (check < x) l = m + 1;
            else r = m - 1;
        }

        if (possible) cout << 10 << endl;
        else cout << 0 << endl;
    }
    else cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}