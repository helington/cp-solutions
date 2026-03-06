#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, a, b; cin >> n >> a >> b;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    ll ans = 0;
    int l = 0, r = 0;
    for (int i = 0; i < a; i++, r++) ans += x[i];

    while (r < n) {

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}