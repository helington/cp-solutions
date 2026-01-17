#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

void solve() {
    int n; cin >> n;

    if (n > 1 and n < 4) cout << "NO SOLUTION" << endl;
    else {
        for (int i = 2; i <= n; i+=2) cout << i << " ";
        for (int i = 1; i <= n; i+=2) cout << i  << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}