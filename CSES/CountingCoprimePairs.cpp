#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 1;

vector<int> getdivisors(int n) {
    vector<int> divisors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i != 1 ) divisors.push_back(i);
            if (i != n/i) divisors.push_back(n/i);
        }
    }


    return divisors;
}

void solve() {
    int n; cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());

    vector<int> values(MAXN, 0);

    int total = 0;
    for (int i = 0; i < n; i++) {
        auto divisors = getdivisors(x[i]);

        int current = 0;
        for (int divisor : divisors) {
            current += values[divisor];
        }
        total += i - current;

        values[x[i]]++;
    }

    cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}