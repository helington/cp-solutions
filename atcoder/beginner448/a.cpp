#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, x; cin >> n >> x;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    for (auto &it : a) {
        if (it < x) {x = it; cout << '1' << endl;}
        else cout << '0' << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}