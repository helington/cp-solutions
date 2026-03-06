#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<ll> pref(n, 0); pref[0] = b[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i- 1] + b[i];

    ll ans = 0;
    ll current_x = 1;
    ll current = 0;
    while (true) {
        auto it = lower_bound(a.begin(), a.end(), current_x);

        int available_swords = a.end() - it;
        auto level = lower_bound(pref.begin(), pref.end(), available_swords);

        if (*level == available_swords) {
            current = level - pref.begin() + 1;
            current *= current_x;
        }
        else {
            if (level == pref.begin()) current = 0;
            else {
                level--;
                current = level - pref.begin() + 1;
                current *= current_x;
            }
        }

        ans = max(ans, current);

        auto it2 = upper_bound(a.begin(), a.end(), current_x);

        if (it2 == a.end()) break;
        current_x = *it2;
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