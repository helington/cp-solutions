#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n, k, L, R; cin >> n >> k >> L >> R;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    auto all = a;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    vector<int> freq1(all.size(), 0);
    vector<int> freq2(all.size(), 0);

    int total1 = 0;
    int total2 = 0;
    ll ans = 0;

    for (int l = 0, r1 = 0, r2 = 0; l < n; l++) {
        while (r1 < n and total1 < k) {
            int idx = lower_bound(all.begin(), all.end(), a[r1]) - all.begin();
            if (!freq1[idx]) total1++;
            freq1[idx]++;
            r1++;
        }

        while (r2 < n and total2 <= k) {
            int idx = lower_bound(all.begin(), all.end(), a[r2]) - all.begin();
            if (!freq2[idx]) {
                if (total2 + 1 > k) break;
                total2++;
            }
            freq2[idx]++;
            r2++;
        }

        if (total1 == k) {
            int curr = max(0, min(r2-1, l+R-1) - max(r1-1, l+L-1) + 1);
            ans += curr;
        }

        int idx = lower_bound(all.begin(), all.end(), a[l]) - all.begin();
        freq1[idx]--, freq2[idx]--;

        if (!freq1[idx]) total1--;
        if (!freq2[idx]) total2--;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}