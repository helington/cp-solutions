#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &it : a) cin >> it.first >> it.second;
    reverse(a.begin(), a.end());

    int curr = 0, ans = 0;
    vector<bool> used(n+1, false);
    vector<int> best(n+1, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    for (auto &it : a) {
        int idx = it.first;
        if (it.second > best[idx]) {
            int diff = it.second - best[idx];
            best[idx] = it.second;

            if (used[idx]) curr += diff;
            else if (pq.size() < 6) {
                pq.push({best[idx], idx});
                curr += best[idx];
                used[idx] = true;
            }
            else {
                if (best[idx] > pq.top().first) {
                    curr -= pq.top().first, used[pq.top().second] = false, pq.pop();
                    curr += best[idx], pq.push({best[idx], idx}), used[idx] = true;;
                }
            }

            ans = max(ans, curr);
        }
    }

    if (!ans) cout << -1 << endl;
    else cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

