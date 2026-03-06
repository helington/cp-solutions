#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int r = a.front();
    stack<int> st;
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
        if (a[i] > r) {
            edges.push_back({r, a[i]});
            while (!st.empty() and st.top() < a[i]) {
                edges.push_back({st.top(), a[i]});
                r = min(r, st.top());
                st.pop();
            }
        } else {
            int curr = a[i];
            while (!st.empty() and st.top() < curr) {
                edges.push_back({st.top(), a[i]});
                curr = min(curr, st.top());
                st.pop();
            }
            st.push(curr);
        }
    }

    if (st.empty()) {
        cout << "Yes" << endl;
        for (auto [u, v] : edges) cout << u << " " << v << endl;
    }
    else cout << "No" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
