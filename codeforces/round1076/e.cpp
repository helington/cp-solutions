#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

const int INF = 1e9 + 10;

void solve() {
    int n; cin >> n;

    vector<bool> divisors(n+1, false);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        divisors[v] = true;
    }

    vector<int> dp(n+1, INF);
    dp[1] = 0;

    for (int i = 1; i <= n; i++) {
        if (dp[i] == INF) continue;

        for (int j = 2 * i; j <= n; j += i) {
            int mult = j / i;

            if (divisors[mult]) {
                if (dp[i] + 1 < dp[j]) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (divisors[1]) cout << 1 << " ";
            else cout << -1 << " ";
        } else {
            if (dp[i] == INF) cout << -1 << " ";
            else cout << dp[i] << " ";
        }
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;

}