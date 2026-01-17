#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define endl '\n'

const int INF = 1e9;

int n;

int best(vector<int> &dp, int i = n) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];

    dp[i] = INF;
    for (int j = 10; j <= i * 10; j *= 10) {
        int digit = i % j / (j / 10);
        dp[i] = min(dp[i], best(dp, i - digit) + 1);
    }

    return dp[i];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << best(dp);

    return 0;
}