#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y; cin >> x >> y;

    for (int i = 0; i < y; i++) x *= 2;

    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}