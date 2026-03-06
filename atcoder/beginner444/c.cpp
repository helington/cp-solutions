#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

vector<ll> getdivisors(ll n) {
    vector<ll> divisors;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n/i) divisors.push_back(n / i);
        }
    }

    sort(divisors.begin(), divisors.end());
    return divisors;
}

void solve() {
    int n; cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> all_pairs;
    for (int i = 1; i < n; i++) {
        all_pairs.push_back(a[0] + a[i]);
    }
    sort(all_pairs.begin(), all_pairs.end());
    all_pairs.erase(unique(all_pairs.begin(), all_pairs.end()), all_pairs.end());

    ll sum = accumulate(a.begin(), a.end(), 0ll);

    auto divisors = getdivisors(sum);

    auto it = lower_bound(divisors.begin(), divisors.end(), a[n-1]);

    vector<ll> ans;
    while (it != divisors.end()) {
        bool possible1 = binary_search(all_pairs.begin(), all_pairs.end(), *it);
        bool possible2 = binary_search(a.begin(), a.end(), *it);
        if (possible1 or possible2) ans.push_back(*it);
        it++;
    }

    for (auto value : ans) cout << value << " ";
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}