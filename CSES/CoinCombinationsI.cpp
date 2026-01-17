#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

int n;

int mod_add(int a, int b) {
    return (a + b) % MOD;
}

void solve() {
    int x; cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (auto c : coins) {
            if (i - c >= 0) dp[i] = mod_add(dp[i], dp[i - c]);
        }
    }

    cout << dp[x] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}