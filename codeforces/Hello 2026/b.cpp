#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

int get_mex(const vector<int> &a, const int n) {
    vector<bool> seen(n + 1, false);

    for (int i : a) {
        if (i >= 0 && i <= n) seen[i] = true;
    }

    int mex = 0;
    while (mex <= n && seen[mex]) mex++;

    return mex;
}

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mex = get_mex(a, n);

    cout << min(mex, k - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}