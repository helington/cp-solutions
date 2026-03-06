#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

const int INF = 1e9 + 10;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n);
    for  (int i = 0; i < n; i++) cin >> a[i];

    set<int> b;
    for (int i = 0; i < m; i++) {
        int value; cin >> value;
        b.insert(value);
    }

    vector<int> needed_to_die_l(n, INF);
    vector<int> needed_to_die_r(n, INF);
    for (int i = 0; i < n; i++) {
        auto it = b.lower_bound(a[i]);
        if (it != b.end()) needed_to_die_r[i] = *it - a[i];
        if (it != b.begin()) {
            it--;
            needed_to_die_l[i] = *it - a[i];
        }
    }

    vector<int> pref_moves(k);
    for (int i = 0; i < k; i++) {
        char move; cin >> move;
        if (move == 'R') pref_moves[i] = 1;
        else pref_moves[i] = -1;
    }

    for (int i = 1; i < k; i++) pref_moves[i] += pref_moves[i - 1];

    map<int, int> mp;
    for (int i = 0; i < k; i++) {
        if (!mp.count(pref_moves[i])) mp[pref_moves[i]] = i;
    }

    vector<int> dies(k, 0);
    for (int i = 0; i < n; i++) {
        int idx = INF;
        if (mp.count(needed_to_die_l[i]))
            idx = min(idx, mp[needed_to_die_l[i]]);
        if (mp.count(needed_to_die_r[i]))
            idx = min(idx, mp[needed_to_die_r[i]]);

        if (idx != INF) dies[idx]++;
    }

    vector<int> ans(k, n); ans[0] -= dies[0];
    for (int i = 1; i < k; i++) ans[i] = ans[i - 1] - dies[i];

    for (int i = 0 ; i < k; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc; // Uncomment if the problem has multiple test cases
    while (tc--) {
        solve();
    }

    return 0;
}