#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

int n, m;

int best(string &s, string &t) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                int pos1 = dp[i][j-1] + 1;
                int pos2 = dp[i-1][j] + 1;
                int pos3 = dp[i-1][j-1] + 1;
                dp[i][j] = min({pos1, pos2, pos3});
            }
        }
    }

    return dp[n][m];
}

void solve() {
    string s; cin >> s;
    string t; cin >> t;

    n = s.length(), m = t.length();

    cout << best(s, t) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}