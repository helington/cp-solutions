#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

int n, x;

int best(vector<pair<int, int>> &a) {
    vector<int> dp(x+1, 0);
    vector<int> dp_aux(x+1);

    for (auto [price, pages] : a) {
        dp_aux = dp;
        for (int j = 0; j + price <= x; j++) {
            dp_aux[j+price] = max(dp[j+price], dp[j] + pages);
        }
        dp = dp_aux;
    }

    return *max_element(dp.begin(), dp.end());
}

void solve() {
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;

    cout << best(a) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}