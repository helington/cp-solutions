#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    string s; cin >> s;
    s += s;

    int ans = 0;
    for (int l = 0, r = n-1; r < 2 * n; l++, r++) {
        char past = '-';
        int curr = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] != past) curr++;
            past = s[i];
        }
        ans = max(ans, curr);
    }

    cout << ans << endl;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}