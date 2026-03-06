#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; i++) cin >> r[i];
    ll past_sum = accumulate(r.begin(), r.end(), 0ll);

    for (int i = 0; i < n - 1; i++) {
        if (r[i + 1] > r[i]) r[i + 1] = r[i] + 1;
    }

    for (int i = n - 1; i > 0; i--) {
        if (r[i - 1] > r[i]) r[i - 1] = r[i] + 1;
    }

    ll current_sum = accumulate(r.begin(), r.end(), 0ll);

    ll ans = past_sum - current_sum;
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