#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

const int INF = 1e9 + 1;

void solve() {
    int n; cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    ll ans = 1;
    ll current = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == a[i - 1] + 1) current++;
        else current = 1;
        ans = max(ans, current);
    }

    cout << ans << endl;
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