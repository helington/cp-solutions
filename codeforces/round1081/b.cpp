#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    string s; cin >> s;
    vector<int> zeros, ones;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zeros.push_back(i+1);
        else ones.push_back(i+1);
    }

    if (n % 2 == 1 and ones.size() % 2 == 1) cout << -1 << endl;
    else {
       if (zeros.size() % 2 == 0) {
           cout << ones.size() << endl;
           for (auto i : ones) cout << i << ' ';
       } else {
           cout << zeros.size() << endl;
           for (auto i : zeros) cout << i << ' ';
       }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}