#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ones = 0, zeros = 0;
    for (auto &c : s) {
        if (c == '0') zeros++;
        else ones++;
    }

    if (zeros == n or ones == n) cout << 0 << endl;
    else {
        cout << zeros << endl;
        for (int i = 0; i < n; i++)
            if (s[i] == '0') cout << i+1 << " ";
        cout << endl;
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