#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

vector<vector<ll>> precompute() {
    vector<vector<ll>> combinations(31, vector<ll>(31, 0));

    for (int i = 0; i <= 30; i++) {
        combinations[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            combinations[i][j] = combinations[i - 1][j - 1] + combinations[i - 1][j];
        }
    }

    return combinations;
}

void solve() {
    ll n, m, t; cin >> n >> m >> t;

    auto combinations = precompute();

    ll mans_to_start = t - n;
    ll mans = (mans_to_start <= 0) ? t - 1 : n;
    ll womans = t - mans;

    ll total = 0;
    while ((womans >= 1 and womans <= m) and
        (mans >= 4 and mans <= n)) {
        ll current = combinations[n][mans] * combinations[m][womans];
        total += current;
        mans--; womans++;
    }

    cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}