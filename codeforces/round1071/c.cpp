#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    cout << max(a[0], a[1] - a[0]) << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}