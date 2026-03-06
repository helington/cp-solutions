#include <bits/stdc++.h>
#include <random>

using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

signed main(int argc, char *argv[]) {
    uniform_int_distribution<int> dist_n(1, 20);
    int n = dist_n(rng);

    vector<int> numbers(n);
    uniform_int_distribution<int> dist(1, 40);
    for (auto &it : numbers) {
        it = dist(rng);
    }

    cout << 1 << endl;
    cout << n << endl;
    for (auto &it : numbers) cout << it << " ";
    cout << endl;
}