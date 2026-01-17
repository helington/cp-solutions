#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    ll n; cin >> n;

    while (n != 1) {
        cout << n << " ";

        if (n % 2 == 0) n /= 2;
        else {n *= 3; n++;}
    }

    cout << n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}