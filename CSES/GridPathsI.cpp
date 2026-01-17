#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

#define MOD 1000000007

int n;

const int di[] = {0, 1};
const int dj[] = {1, 0};

int mod_add(int a, int b) {
    return (a + b) % MOD;
}

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

int total_ways(vector<vector<int>> &dp, vector<string> &grid, int i = 0, int j = 0) {
    if (!is_valid(i, j) or grid[i][j] == '*') return 0;
    if (i == n - 1 and j == n - 1) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 0;

    for (int k = 0; k < 2; k++) {
        int ni = i + di[k]; int nj = j + dj[k];
        dp[i][j] = mod_add(dp[i][j], total_ways(dp, grid, ni, nj));
    }

    return dp[i][j];
}

void solve() {
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << total_ways(dp, grid) << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}