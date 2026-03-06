#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int n = (int) s.size();

    int total_s = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 's') total_s++;
        else {
            if (i > 0 and i < n - 1) {
                if (s[i-1] == 'u') total_s++, ans++, s[i-1] = 's';
                if (s[i+1] == 'u') total_s++, ans++, s[i+1] = 's';
            }
        }
    }

    if (s.front() == 'u') ans++;
    if (s.back() == 'u') ans++;

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}