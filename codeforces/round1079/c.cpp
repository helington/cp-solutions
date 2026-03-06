#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    ll p, q; cin >> p >> q;

    ll diff = q - p;
    if (p < q and min(p/2, q/3) >= diff) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}