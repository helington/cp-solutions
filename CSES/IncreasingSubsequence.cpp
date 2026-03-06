#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long

int n;

int lis(vector<int> &x) {
    vector<int> dp; dp.push_back(x[0]);

    for (int i = 1; i < n; i++) {
        if (x[i] > dp.back()) dp.push_back(x[i]);
        else {
            int idx = lower_bound(dp.begin(), dp.end(), x[i]) - dp.begin();
            dp[idx] = x[i];
        }
    }

    return dp.size();
}

void solve() {
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << lis(x) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}