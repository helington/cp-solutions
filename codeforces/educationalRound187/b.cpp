#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl "\n"

void solve() {
    ll n; cin >> n;

    vector<pair<ll, bool>> v;
    ll total = 0ll;
    while (n) {
        ll digit = n % 10;
        total += digit;
        v.push_back({digit, false});
        n /= 10;
    }
    v.back().second = true;
    sort(v.begin(), v.end(), [&](pair<ll, bool> &a, pair<ll, bool> &b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    ll ans = 0;
    auto it = v.begin();
    while (total >= 10) {
        total -= it->first;
        if (it->second) total++;
        it++;
        ans++;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}