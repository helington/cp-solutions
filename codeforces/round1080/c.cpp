#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const ll INF = 2e9;

int n;

int oppositive(int x) { return 7 - x; }

int best(
    vector<vector<int>> &dp,
    vector<int> &a,
    int i=0, int j=0
    ) {
    if (i == n) return 0;

    int &ans = dp[i][j];
    if (ans != -1) return ans;

    ans = INF;
    for (int k = 1; k <= 6; k++) {
        if (k == oppositive(j) or k == j) continue;

        int inc = (k != a[i]);
        ans = min(ans, inc + best(dp, a, i+1, k));
    }

    return ans;
}

void solve() {
    cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    vector<vector<int>> dp(n, vector<int>(7, -1));

    cout << best(dp, a) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}