#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

const int BITS = 31;

void solve() {
    int a, b; cin >> a >> b;


    if (b == a) cout << 0 << endl;
    else {
        vector<int> ans;
        int curr;

        for (int i = 1; i <= 100; i++) {
            curr = 0;
            for (int i = 0; i < BITS; i++) {
                int bit1 = (a >> i) & 1, bit2 = (b >> i) & 1;

                if (bit1 == bit2) continue;
                if ((curr ^ (1 << i)) > a) continue;

                curr = (curr ^ (1 << i));
            }

            ans.push_back(curr);
            a = a ^ curr;

            if (a == b) break;
        }

        if (a == b) {
            cout << ans.size() << endl;
            for (auto &it : ans) cout << it << " ";
            cout << endl;
        } else cout << -1 << endl;

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