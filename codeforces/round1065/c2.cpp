#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

const int BITS = 30;

void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);
    int xor_total = 0;
    for (auto &it : a) cin >> it, xor_total ^= it;
    for (auto &it : b) cin >> it, xor_total ^= it;

    if (!xor_total) cout << "Tie" << endl;
    else {
        bool Mai = true;
        int best = -1;
        for (int i = n-1; i >= 0; i--) {
            for (int j = BITS; j >= 0; j--) {
                int bit1 = (a[i] ^ b[i]) & (1 << j);
                int bit2 = xor_total & (1 << j);
                if (bit1 and bit2) {
                    if (j > best) {
                        best = j;
                        if (i % 2 == 0) Mai = false;
                        else Mai = true;
                        break;
                    }
                }
            }
        }
        if (Mai) cout << "Mai" << endl;
        else cout << "Ajisai" << endl;
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