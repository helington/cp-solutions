#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    int years = 0;

    int total = n;

    while (total < k) {
        years++;
        total += years + n;
    }

    cout << years << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}