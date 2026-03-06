#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

const int INF = 1e9 + 10;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    auto sorted = a;
    sort(sorted.begin(), sorted.end());

    if (sorted == a) { cout << -1 << endl; return; }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (a[i] == sorted[i]) continue;
        int possible1 = abs(a[i] - sorted[0]);
        int possible2 = abs(a[i] - sorted[n-1]);
        int curr = max(possible1, possible2);
        ans = min(ans, curr);
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