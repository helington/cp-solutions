#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;

    vector<int> positions(n+1);
    for (int i = 0; i < n; i++) {
        int p; cin >> p;

        positions[p] = i;
    }

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    // Primeira verificaçã: não pode pular
    vector<int> last_time(n+1, -1);
    for (int i = 0; i < n; i++) {
        if (last_time[a[i]] != -1 and last_time[a[i]] < i - 1) {
            cout << "NO" << endl;
            return;
        }
        last_time[a[i]] = i;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) {
            if (positions[a[i]] < positions[a[i-1]]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}