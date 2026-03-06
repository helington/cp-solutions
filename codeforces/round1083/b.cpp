#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

vector<ll> getprimes(int n) {
    vector<ll> primes;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) primes.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) primes.push_back(n);

    return primes;
}

void solve() {
    int n; cin >> n;

    vector<ll> primes = getprimes(n);
    ll ans = 1;
    for (auto &it : primes) ans *= it;

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}