#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define endl '\n'

ll getdivisorssum(ll n) {
    ll ans = 0;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans += i;

            if (n / i != i) ans += n/i;
        }
    }

    return ans;
}

void solve() {
    ll n; cin >> n;

    ll ans = getdivisorssum(n);

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}