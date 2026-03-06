#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int current = n;
    for (int i = 0; i < n; i++) {
        if (p[i] != current) {
            int j = i + 1;
            for (; j < n; j++) if (p[j] == current) break;
            j++;

            reverse(p.begin() + i, p.begin() + j);
            break;
        }
        current--;
    }

    for (int i = 0; i < n; i++) cout << p[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >>tc; while (tc--) {
        solve();
    }

    return 0;
}