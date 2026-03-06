#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int MAXN = -1;

    int n; cin >> n;

    vector<int> a(n);

    vector<vector<int>> all(n);

    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        all[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> all[i][j];
            MAXN = max(MAXN, all[i][j]);
        }
        reverse(all[i].begin(), all[i].end());
        a[i] = i;
    }
    vector<bool> used(MAXN+1, false);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k1 = 0, k2 = 0;

            bool swaped = false;
            while (k1 < all[a[i]].size() and k2 < all[a[j]].size()) {
                while (k1 < all[a[i]].size() and used[all[a[i]][k1]]) k1++;
                while (k1 < all[a[i]].size() - 1 and all[a[i]][k1] == all[a[i]][k1+1]) k1++;
                while (k2 < all[a[j]].size() and used[all[a[j]][k2]]) k2++;
                while (k2 < all[a[j]].size() - 1 and all[a[j]][k2] == all[a[j]][k2+1]) k2++;

                if (k1 >= all[a[i]].size() or k2 >= all[a[j]].size()) {
                    break;
                }

                if (all[a[j]][k2] != all[a[i]][k1]) {
                    if (all[a[j]][k2] < all[a[i]][k1]) swaped = true;
                    break;
                }
                k1++, k2++;
            }

            if (!swaped and k2 == all[a[j]].size() and k1 != all[a[i]].size()) swaped = true;

            if (swaped) swap(a[i], a[j]);
        }

        for (auto j : all[a[i]]) {
            if (!used[j]) cout << j << " ";
            used[j] = true;
        }
    }

    cout << endl;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}