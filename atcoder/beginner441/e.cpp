#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl '\n'

template<typename T>
struct BIT {
    int N;
    vector<T> bit;

    BIT(int n) : N(n+1), bit(n+1, 0) {}

    BIT(const vector<T> &v) : N(v.size() + 1), bit(v.size() + 1, 0) {
        for (int i = 0; i < v.size(); i++) {
            bit[i + 1] = v[i];
        }

        for (int i = 1; i < N; i++) {
            int parent = i + (i & -i);
            if (parent < N) bit[parent] += bit[i];
        }
    }

    void update(int idx, T val) {
        for (; idx < N; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    T query(int idx) {
        T sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    T query(int l, int r) {
        return query(r) - query(l-1);
    }
};

void solve() {
    int n; cin >> n;

    string s; cin >> s;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') values[i] = 1;
        else if (s[i] == 'B') values[i] = -1;
    }

    vector<int> all;
    for (int i = -n; i <= n; i++) all.push_back(i);
    BIT<int> bit(all.size());

    int idx0 = lower_bound(all.begin(), all.end(), 0) - all.begin() + 1;
    bit.update(idx0, 1);

    vector<int> pref(n, 0); pref[0] = values[0];
    for (int i = 1; i < n; i++) pref[i] = values[i] + pref[i-1];

    int total = 0;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(all.begin(), all.end(), pref[i] - 1) - all.begin() + 1;
        total += bit.query(0, idx);
        bit.update(idx+1, 1);
    }

    cout << total << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}