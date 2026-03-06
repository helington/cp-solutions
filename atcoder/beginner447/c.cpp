#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    string s; cin >> s;
    string t; cin >> t;

    int n = (int) s.size(), m = (int) t.size();

    string without_a_s = "";
    for (auto &c : s)
        if (c != 'A') without_a_s += c;

    string without_a_t = "";
    for (auto &c : t)
        if (c != 'A') without_a_t += c;

    if (without_a_s != without_a_t) cout << -1 << endl;
    else {
        int ans = 0;
        int j_s = 0, j_t = 0;
        for (int i = 0; i < without_a_s.size()+1; i++) {
            int curr_s = 0, curr_t = 0;
            while (j_s < n and s[j_s] == 'A') {curr_s++; j_s++;}
            while (j_t < m and t[j_t] == 'A') {curr_t++; j_t++;}

            int curr = abs(curr_s - curr_t);
            ans += curr;
            j_s++, j_t++;
        }

        cout << ans << endl;

    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}