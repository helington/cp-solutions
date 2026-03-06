#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

bool Comp(const tuple<int, int, int> &p1, const tuple<int, int, int> &p2) {
    if (max(get<0>(p1), get<1>(p1)) > max(get<0>(p2), get<1>(p2))) return true;
    return false;
}

void solve() {
    int H, W, N; cin >> H >> W >> N;

    vector<int> h(N), w(N);
    for (int i = 0; i < N; i++) cin >> h[i] >> w[i];

    vector<int> ord_h(N), ord_w(N);
    iota(ord_h.begin(), ord_h.end(), 0);
    sort(ord_h.begin(), ord_h.end(), [&](int i, int j) { return h[i] > h[j]; });
    iota(ord_w.begin(), ord_w.end(), 0);
    sort(ord_w.begin(), ord_w.end(), [&](int i, int j) { return w[i] > w[j]; });

    auto it1 = ord_h.begin(), it2 = ord_w.begin();
    vector<bool> used(N, false);

    int left = 0, upper = 0;

    vector<pair<int, int>> ans(N);

    for (int i = 0; i < N; i++) {
        while (used[*it1]) it1++;
        while (used[*it2]) it2++;

        int idx = (h[*it1] == H) ? *it1 : *it2;

        used[idx] = true;
        ans[idx] = {upper + 1, left + 1};

        if (h[idx] == H) {
            left += w[idx];
            W -= w[idx];
        } else {
            upper += h[idx];
            H -= h[idx];
        }
    }

    for (auto it : ans) cout << it.first << " " << it.second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}