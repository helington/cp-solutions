#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl '\n'

vector<pair<int, int>> sieve(int n, vector<int> &x) {
    vector<vector<int>> primes(n+1);

    // marcar os divisores primos de cada numero
    for (int i = 2; i <= n; i++) {
        if (primes[i].empty()) {
            primes[i].push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                primes[j].push_back(i);
            }
        }
    }

    // marca a frequencia de cda numero
    vector<int> freq(n+1, 0);
    for (auto &idx : x) freq[idx]++;

    vector<pair<int, int>> res(n+1);
    for (int i = 0; i <= n; i++) res[i] = {0, -1};

    // res[x] fala quando elementos são divisiveis por x no array, e qnts fatores primos dividem x;
    for (int i = 2; i <= n; i++) {
        if (freq[i]) {
           for (int mask = 1; mask < (1 << primes[i].size()); mask++) {
               int key = 1;
               for (int j = 0; j < primes[i].size(); j++) {
                   if (mask & (1 << j)) key *= primes[i][j];
               }
               res[key].first += freq[i];
               if (res[key].second == -1) res[key].second = __builtin_popcount(mask);
           }
        }
    }

    return res;
}

int binomial(int n) {
    if (n < 2) return 0;
    return (n * (n - 1)) / 2;
}

void solve() {
    int n; cin >> n;

    vector<int> x(n);
    for (auto &it : x) cin >> it;
    int MAXN = *max_element(x.begin(), x.end());

    auto prime_divisors = sieve(MAXN, x);

    int total = binomial(n);

    int non_coprimes = 0;
    for (auto curr : prime_divisors) {
        if (curr.second == -1) continue;

        int comb = binomial(curr.first);

        if (curr.second % 2 == 0) non_coprimes -= comb;
        else non_coprimes += comb;
    }

    total -= non_coprimes;

    cout << total << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}