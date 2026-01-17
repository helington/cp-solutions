#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl '\n'

void solve() {
    int s, k, m; cin >> s >> k >> m;

    if (s == k) {
        int ans;
        if (m >= k) {
            ans = k - m % k;
            if (ans == 0) ans = k;
        }
        else {
            ans = k - m;
        }
        cout << ans << endl;
    }
    else if (s < k) {
        int total = (m / k) * k + s;
        int ans = total - m;
        if (ans < 0) ans = 0;
        cout << ans << endl;
    }
    else {
        int ans;
        int turn = m / k;
        if (turn % 2 == 0) {
            ans = s - (m % k);
        } else {
            ans = k - (m % k);
            if (ans == 0) ans = k;
        }
        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}