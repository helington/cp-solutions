#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

#define MAXN 1e5+1

void solve() {
    int n; cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());

    vector<bool> dp(MAXN, false); dp[0] = true;
    vector<bool> dp_aux(MAXN);

    for (int i = 0; i < n; i++) {
        dp_aux = dp;
        for (int j = 0; j < MAXN; j++) {
            if (x[i] + j >= MAXN) break;
            if (dp[j]) dp_aux[x[i] + j] = true;
        }
        dp = dp_aux;
    }

    vector<int> ans;
    for (int i = 1; i < MAXN; i++) if (dp[i]) ans.push_back(i);

    cout << ans.size() << endl;
    for (auto i : ans) cout << i << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}