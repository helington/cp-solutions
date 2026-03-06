#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const int MAXN = 1e6;

pair<vector<int>, vector<int>> sieve() {
    vector<int> factors(MAXN+1, 0);
    vector<int> spf(MAXN+1, 0);
    spf[1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        if (!factors[i]) {
            spf[i] = i;
            for (int j = 2 * i; j <= MAXN; j += i) {
                factors[j]++;
                if (!spf[j]) spf[j] = i;
            }
        }
    }

    // 0 diz que é primo

    return {factors, spf};
}


void solve(vector<int> &factors, vector<int> &spf) {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &it: a) cin >> it;

    auto sorted = a;
    sort(sorted.begin(), sorted.end());

    if (a == sorted) cout << "Bob" << endl;
    else {
        // se só tiver primo não consegue jogar
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (factors[a[i]]) { flag = false; break; }
        }
        if (flag) { cout << "Alice" << endl; return; }

        // se algum tiver mais do q dois fatores
        for (int i = 0; i < n; i++) {
            if (factors[a[i]] > 1) { cout << "Alice" << endl; return; }
        }

        // se os fatores primos não tiverem ordenados
        for (int i = 1; i < n; i++) {
            if (spf[a[i-1]] > spf[a[i]]) { cout << "Alice" << endl; return; }
        }

        cout << "Bob" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto [factors, spf] = sieve();

    int tc; cin >> tc; while (tc--) {
        solve(factors, spf);
    }

    return 0;
}