#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

const int INF = 1e9 + 10;

template<typename T>
struct SegTree {
    int N;
    vector<T> seg;

    // Define based on specific problem: 0 for Sum, INF for Min, -INF for Max
    const T NEUTRAL = INF;

    SegTree(int n) : N(n), seg(4 * n, NEUTRAL) {}

    SegTree(const vector<T> &v) : N(v.size()), seg(4 * v.size(), NEUTRAL) {
        build(v, 1, 0, N - 1);
    }

    T join(T vl, T vr) {
        return min(vl, vr);
    }

    void build(const vector<T> &v, int p, int l, int r) {
        if (l == r) {
            seg[p] = v[l];
            return;
        }

        int m = (l + r) / 2;

        build(v, 2 * p, l, m);
        build(v, 2 * p + 1, m + 1, r);

        seg[p] = join(seg[2 * p], seg[2 * p + 1]);
    }

    T query(int a, int b, int p, int l, int r) {
        if (b < l or r < a) return NEUTRAL;
        if (a <= l and r <= b) return seg[p];

        int m = (l + r) / 2;

        return join(query(a, b, 2 * p, l, m),
                    query(a, b, 2 * p + 1, m + 1, r));
    }

    T query(int a, int b) { return query(a, b, 1, 0, N - 1); }

    void update(int idx, T val, int p, int l, int r) {
        if (idx < l or r < idx) return;
        if (l == r) {
            seg[p] = val;
            return;
        }

        int m = (l + r) / 2;

        update(idx, val, 2 * p, l, m);
        update(idx, val, 2 * p + 1, m + 1, r);

        seg[p] = join(seg[2 * p], seg[2 * p + 1]);
    }

    void update(int idx, T val) { update(idx, val, 1, 0, N - 1); }
};

void solve() {
    int n, q; cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    SegTree<int> seg(v);

    while (q--) {
        int op; cin >> op;

        if (op == 1) {
            int k, u; cin >> k >> u; k--;

            seg.update(k, u);
        } else {
            int l, r; cin >> l >> r; l--; r--;

            cout << seg.query(l, r) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}