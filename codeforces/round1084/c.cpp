#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    stack<char> st;
    for (int i = 0; i < n; i++) {
        if (!st.empty() and st.top() == s[i]) st.pop();
        else st.push(s[i]);
    }

    if (st.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}