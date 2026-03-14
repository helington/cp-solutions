#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

const int INF = 1e9 + 10;

void solve() {
    int n, q; cin >> n >> q;

    vector<int> a(n);
    multiset<int> st;
    for (auto &it : a) {cin >> it; st.insert(it);}

    while (q--) {
        int m; cin >> m;
        vector<int> b(m);
        for (auto &it : b) {cin >> it; it--;}

        for (auto &it : b)
            st.erase(st.find(a[it]));
        cout << *st.begin() << endl;
        for (auto &it : b)
            st.insert(a[it]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}