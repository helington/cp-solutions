#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

bool Comp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second > p2.second;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<pair<int, int>> a(n), b(m);
    for (auto &it : a) cin >> it.first >> it.second;
    for (auto &it : b) cin >> it.first >> it.second;
    sort(a.begin(), a.end(), Comp);

    priority_queue<int, vector<int>, greater<int>> pq;

    ll s = 0; ll curr = 0;
    auto it = a.begin();
    for (int k = n; k > 0; k--) {
        while (pq.size() > k) { curr -= pq.top(), pq.pop(); }
        while (it != a.end() and it->second >= k - 1) {
            if (pq.size() < k) { pq.push(it->first), curr += it->first; }
            else if (pq.top() < it->first) {
                curr -= pq.top(), pq.pop();
                curr += it->first, pq.push(it->first);
            }
            it++;
        }
        s = max(s, curr);
    }

    vector<ll> pref(n+2, 0);
    it = a.begin();
    curr = 0;
    while (!pq.empty()) pq.pop();
    for (int k = n+1; k > 1; k--) {
        while (pq.size() > k - 1) { curr -= pq.top(), pq.pop(); }
        while (it != a.end() and it->second >= k - 1) {
            if (pq.size() < k - 1) { pq.push(it->first), curr += it->first; }
            else if (pq.top() < it->first) {
                curr -= pq.top(), pq.pop();
                curr += it->first, pq.push(it->first);
            }
            it++;
        }
        pref[k] = curr;
    }

    for (int i = 1; i <= n+1; i++) pref[i] = max(pref[i], pref[i-1]);

    vector<ll> ans(m);

    for (int i = 0; i < m; i++) {
        ans[i] = max(s, pref[b[i].second + 1] + b[i].first);
    }

    for (auto &it : ans) cout << it << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}