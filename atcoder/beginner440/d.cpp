#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        int x, y; cin >> x >> y;
        int ans;

        while (true) {
            auto it = lower_bound(a.begin(), a.end(), x);

            if (x == *it) x++;
            else if (it == a.end()) {
                ans = x; break;
            }
            else {
                if (y == 0) {ans = y+1; break;}

                int diff = (*it - x);

                if (diff >= y) {ans = y - diff + x - 1; break;}

                y -= diff;
                x = *it;
            }
        }

        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}