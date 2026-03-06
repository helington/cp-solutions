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
    for (int i = 1; i < n; i++) {
        if (a[i] > r) {
            while (!st.empty() and st.top() < a[i]) {
                r = min(r, st.top());
                st.pop();
            }
        } else {
            int curr = a[i];
            while (!st.empty() and st.top() < curr) {
                curr = min(curr, st.top());
                st.pop();
            }
            st.push(curr);
        }
    }

    if (st.empty()) cout << "Yes" << endl;
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