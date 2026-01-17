#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    ll n; cin >> n;

    ll sum = 0;

    set<ll> numbers;
    for (ll i = 1; i <= n; i++) {numbers.insert(i); sum += i;}

    if (sum % 2 == 1) cout << "NO" << endl;
    else {
        sum /= 2;
        cout << "YES" << endl;

        set<ll> numbers2;

        while (sum > 0) {
            auto it = lower_bound(numbers.begin(), numbers.end(), sum);
            if (it == numbers.end()) it--;

            sum -= *it;
            numbers2.insert(*it); numbers.erase(*it);
        }

        cout << numbers.size() << endl;
        for (auto number : numbers) cout << number << ' ';
        cout << endl;

        cout << numbers2.size() << endl;
        for (auto number : numbers2) cout << number << ' ';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}