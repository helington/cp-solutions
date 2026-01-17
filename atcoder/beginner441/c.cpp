#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl '\n'

int n, k;

bool check(vector<int> &a, int m, int x) {
    int total = 0;
    for (int i = n-1, count=0; i >= 0 and count < m; i--, count++) {
        if (i < k) total += a[i];

        if (total >= x) return true;
    }
    return false;
}

void solve() {
    int x; cin >> n >> k >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int l=0, r=n, m;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (check(a, m, x)) r = m - 1;
        else l = m + 1;
    }

    if (r + 1 > n) cout << -1 << endl;
    else cout << r + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}