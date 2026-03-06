#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

int n, m;

void total_ways(
    vector<vector<int>> &dp, int i, int j,
    int mask, int new_mask
    ) {
    if (i == n) {
        dp[j+1][new_mask] = (dp[j+1][new_mask] + dp[j][mask]) % MOD;
        return;
    }

    if ((mask & (1 << i))) {
        total_ways(dp, i+1, j, mask, new_mask);
    } else {
        total_ways(dp, i+1, j, mask, new_mask | (1<<i));

        if (i + 1 < n and !(mask & (1 << (i + 1)))) {
            total_ways(dp, i+2, j, mask, new_mask);
        }
    }
}

void solve() {
    cin >> n >> m;

    vector<vector<int>> dp(m+1, vector<int>((1<<n), 0));
    dp[0][0] = 1;

    for (int j = 0; j < m; j++) {
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[j][mask]) total_ways(dp, 0, j, mask, 0);
        }
    }

    cout << dp[m][0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}