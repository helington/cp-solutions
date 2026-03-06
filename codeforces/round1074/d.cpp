#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

void solve() {
    int n, m, h; cin >> n >> m >> h;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> initial_a = a;

    vector<ll> b(m), c(m);
    for (int i = 0; i < m; i++) cin >> b[i] >> c[i];

    int last_reset = -1;
    vector<int> a_last_resets(n, -1);

    for (int i = 0; i < m; i++) {
        if (a_last_resets[b[i] - 1] != last_reset) {
            a_last_resets[b[i] - 1] = last_reset;
            a[b[i] - 1] = initial_a[b[i] - 1];
        }
        a[b[i] - 1] += c[i];
        if (a[b[i] - 1] > h) {
            a[b[i] - 1] = initial_a[b[i] - 1];
            last_reset = i;
            a_last_resets[b[i] - 1] = last_reset;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a_last_resets[i] != last_reset) a[i] = initial_a[i];
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}