#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

struct Comp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    }
};

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto all = a;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    vector<int> modes(all.size(), 0);
    set<pair<int, int>, Comp> window;
    for (auto i : all) window.insert({i, 0});

    for (int i = 0; i < k; i++) {
        int idx = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
        window.erase({a[i], modes[idx]});
        modes[idx]++;
        window.insert({a[i], modes[idx]});
    }

    cout << window.begin()->first << " ";

    for (int l = 0, r = k; r < n; l++, r++) {
        int idx_l = lower_bound(all.begin(), all.end(), a[l]) - all.begin();
        int idx_r = lower_bound(all.begin(), all.end(), a[r]) - all.begin();

        window.erase({a[l], modes[idx_l]});
        modes[idx_l]--;
        window.insert({a[l], modes[idx_l]});

        window.insert({a[r], modes[idx_r]});
        modes[idx_r]++;
        window.insert({a[r], modes[idx_r]});

        cout << window.begin()->first << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}