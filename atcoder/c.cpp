#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

ll binomial(ll n) {
    ll res = n * (n - 1) * (n - 2);

    res /= 6;

    return res;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<ll> conflits(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        conflits[a]++; conflits[b]++;
    }

    for (int i = 0; i < n; i++) {
        ll total = n - conflits[i] - 1;

        if (total < 3) cout << 0;
        else cout << binomial(total);
        cout << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}