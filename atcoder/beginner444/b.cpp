#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'



void solve() {
    int n, k; cin >> n >> k;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int curr = i; int sum = 0;

        while (curr > 0) {
            sum += curr % 10;
            curr /= 10;
        }

        if (sum == k) ans++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}