#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll, ll>

const ll INF = 1e10;

int n;
pll aux;

pll best(
    vector<vector<pll>> &dp, vector<ll> &x,
    int i = 0, int j = n - 1
    ) {

    if (dp[i][j].first != -INF) return dp[i][j];

    if (i == j) return {x[i], 0};

    aux = best(dp, x, i + 1, j);
    pll possible1 = {x[i] + aux.second, aux.first};

    aux = best(dp, x, i, j - 1);
    pll possible2 = {x[j] + aux.second, aux.first};

    return dp[i][j] = (possible1 > possible2) ? possible1 : possible2;
}

void solve() {
    cin >> n;

    vector<ll> x(n);
    for (int i = 0 ; i < n ; i++) cin >> x[i];

    vector<vector<pll>> dp(n, vector<pll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) dp[i][j] = {-INF, -INF};
    }

    auto ans = best(dp, x);

    cout << ans.first << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}