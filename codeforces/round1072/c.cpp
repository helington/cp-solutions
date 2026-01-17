#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    int minutes = 0;

    while (n > k) {
        minutes++;
        int n1 = n / 2;
        int n2 = (n % 2 == 0) ? n1 : n1 + 1;

        if (n1 == k or n2 == k) n = k;
        else {
            if (n1 % 2 == 1) n = n1;
            else n = n2;
        }
    }

    if (n == k) cout << minutes << endl;
    else cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}