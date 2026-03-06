#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, d; cin >> n >> m >> d;

    if (m > d) cout << n << endl;
    else {
        int boxes = d / m + 1;
        int ans = n / boxes;
        if (n % boxes) ans++;

        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}