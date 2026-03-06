#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    string s; cin >> s;

    char past='-';
    int curr = 0, ans = 0;
    for (auto &c : s) {
        if (c == past) curr++;
        else curr = 1;
        past = c;
        ans = max(ans, curr);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}