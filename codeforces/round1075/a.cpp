#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n, h, l; cin >> n >> h >> l;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int min_axi = min(h, l), max_axi = max(h, l);

    int left = 0, right = n-1;
    for (;right > 0; right--) if (a[right] <= max_axi) break;

    int ans = 0;
    while (left < right) {
        if (a[left] <= min_axi) {
            ans++;
            left++, right--;
        } else break;
    }

    cout << ans << endl;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}