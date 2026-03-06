#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    string s; cin >> s;

    int a = 0, ab = 0;
    int ans = 0;

    for (auto &c : s) {
        if (c == 'A') a++;
        if (c == 'B' and a) {a--, ab++;}
        if (c == 'C' and ab) {ab--, ans++;}
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}