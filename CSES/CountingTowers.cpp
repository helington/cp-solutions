#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

#define ll long long
#define MOD 1000000007
#define MAXN 1e6

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<ll, ll>> dp(MAXN);
    dp[MAXN - 1] = {1, 1};

    for (int i = MAXN - 2; i >= 0; i--) {
        dp[i].first = (2 * dp[i + 1].first + dp[i + 1].second) % MOD;
        dp[i].second = (4 * dp[i + 1].second + dp[i + 1].first) % MOD;
    }

    int tc; cin >> tc; while (tc--) {
        int n; cin >> n;

        cout << (dp[MAXN - n].first + dp[MAXN - n].second) % MOD << endl;
    }
}