#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

int n;

int solve(
    vector<int> &dp, vector<int> &a, int i
    ) {
    if (i == a[i]) return dp[i] = i;
    if (dp[i] != -1) return dp[i];

    return dp[i] = solve(dp, a, a[i]);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> dp(n+1, -1);

    for (int i = 1; i <= n; i++) cout << solve(dp, a, i) << " ";
    cout << endl;

    return 0;
}