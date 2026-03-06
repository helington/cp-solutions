#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const int MAXN = 1e6;

vector<int> sieve() {
    vector<int> factors(MAXN+1, 0);
    factors[0] = factors[1] = 0;

    for (int i = 2; i <= MAXN; i++) {
        if (!factors[i]) {
            for (int j = 2 * i; j <= MAXN; j += i) {
                factors[j]++;
            }
        }
    }

    // 0 diz que é primo
    factors[1] = 0;

    return factors;
}


void solve(vector<int> &factors) {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it: a) cin >> it;

    auto sorted = a;
    sort(sorted.begin(), sorted.end());

    if (a == sorted) cout << "Bob" << endl;
    else {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (factors[a[i]]) {flag = false; break; }
        }
        if (flag) {cout << "Alice" << endl; return;}

        for (int i = 0; i < n; i++) {
            if (factors[a[i]] > 1) {cout << "Alice" << endl; return;}
        }
        cout << "Bob" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto factors = sieve();

    int tc; cin >> tc; while (tc--) {
        solve(factors);
    }

    return 0;
}
