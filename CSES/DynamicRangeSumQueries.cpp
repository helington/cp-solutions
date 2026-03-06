#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define int long long

struct BIT {
    int N;
    vector<int> bit;

    BIT(int n) : N(n+1), bit(n+1, 0) {}

    BIT(const vector<int> &v) : N(v.size()+1), bit(v.size()+1, 0) {
        for (int i = 0; i < N; i++) {
            bit[i + 1] = v[i];
        }

        for (int i = 1; i <= N; i++) {
            int parent = i + (i & -i);
            if (parent < N) bit[parent] += bit[i];
        }
    }

    void update(int idx, int val) {
        for (; idx < N; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    int query(int l, int r) {
        return query(r) - query(l-1);
    }
};

void solve() {
    int n, q; cin >> n >> q;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    BIT bit(x);

    while (q--) {
        int type; cin >> type;

        if (type == 1) {
            int k, u; cin >> k >> u;

            int diff = u - x[k-1];
            bit.update(k, diff);
            x[k-1] = u;
        }
        else {
            int l, r; cin >> l >> r;
            cout << bit.query(l, r) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}