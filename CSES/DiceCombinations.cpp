#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

ll mod_add(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}

ll total_ways(vector<ll> &dp, const ll sum) {
    if (sum == 0) return 1;
    if (dp[sum] != -1) return dp[sum];

    dp[sum] = 0ll;
    for (ll i = 1; i <= 6 and sum - i >= 0; i++) {
        dp[sum] = mod_add(dp[sum], total_ways(dp, sum - i));
    }

    return dp[sum];
}

void solve() {
    ll n; cin >> n;

    vector<ll> dp(n + 1, -1);

    cout << total_ways(dp, n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}