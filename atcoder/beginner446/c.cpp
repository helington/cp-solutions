#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n, d; cin >> n >> d;

    deque<pair<int, int>> dq;

    vector<pair<int, int>> eggs(n);
    for (auto &it : eggs) cin >> it.first;
    for (auto &it : eggs) cin >> it.second;


    for (int i = 0; i < n; i++) {
        dq.push_back({i, eggs[i].first});

        while (!dq.empty() and dq.front().second < eggs[i].second) {
            eggs[i].second -= dq.front().second; dq.pop_front();
        }
        dq.front().second -= eggs[i].second;
        if (!dq.front().second) dq.pop_front();

        // remover ovos
        while (!dq.empty() and dq.front().first + d <= i) dq.pop_front();
    }

    int ans = 0;
    while (!dq.empty()) ans += dq.front().second, dq.pop_front();

    cout << ans << endl;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}