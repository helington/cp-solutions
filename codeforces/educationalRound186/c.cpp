#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n; i < 2 * n; i++) a[i] = a[i - n];

    vector<int> b(2 * n);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = n; i < 2 * n; i++) b[i] = b[i - n];

    vector<int> c(2 * n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = n; i < 2 * n; i++) c[i] = c[i - n];

    ll cnt1 = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (b[j] <= a[i+j]) { flag = false; break; }
        }
        if (flag) cnt1++;
    }

    ll cnt2 = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (b[j] >= c[i+j]) { flag = false; break; }
        }
        if (flag) cnt2++;
    }

    ll ans = cnt1 * cnt2 * ((ll) n);

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