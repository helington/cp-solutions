#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    if (n <= 3) {cout << n << endl; return;}

    if (n % 2 == 0) cout << 0 << endl;
    else if (n != 5 and n % 5 == 0) cout << 0 << endl;
    else cout << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}