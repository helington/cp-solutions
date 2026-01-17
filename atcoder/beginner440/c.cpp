#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, w; cin >> n >> w;

    vector<ll> c(n);
    for (int i = 0;i < n; i++) cin >> c[i];

    vector<ll> mods(4 * w, 0);
    for (int i = 0;i < n; i++) mods[i % (2 * w)] += c[i];

    for (int i = 2 * w; i < 4 * w; i++) mods[i] = mods[i - 2 * w];

    ll window = 0;
    for (int i = 0; i < w; i++) window += mods[i];

    ll ans = window;
    for (int l = 0, r = w; r < 4 * w; l++, r++) {
        window -= mods[l];
        window += mods[r];
        ans = min(ans, window);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}