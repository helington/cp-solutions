#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl "\n"

multiset<ll> nums;
int n;

bool check(vector<ll> &a, ll h, int m) {
    auto curr = nums;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    ll total = 0;

    for (int i = 0; i < m; i++) {
        total += a[i];
        curr.erase(curr.find(a[i]));
        pq.push(a[i]);
    }

    if (total >= h) return true;
    if (m == n) return false;

    auto it = curr.end(); it--;
    total += *it, total -= pq.top();

    return total >= h;
}

void solve() {
    ll h, k; cin >> n >> h >> k;

    vector<ll> a(n);
    for (auto &it : a) {cin >> it; nums.insert(it);}

    ll total = accumulate(a.begin(), a.end(), 0ll);

    ll quocient = h / total;
    ll ans = quocient * n;
    ans += k * quocient;

    ll rest = h % total;
    if (!rest) {
        ans -= k;
        cout << ans << endl;
    }
    else {
        int l = 1, r = n, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (check(a, rest, m)) r = m - 1;
            else l = m + 1;
        }

        ans += r + 1;

        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        nums.clear();
        solve();
    }

    return 0;
}