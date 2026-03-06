#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            int j = 2*i;

            bool ok = false;

            while (j <= n) {
                if (a[j] == i) {
                    swap(a[i], a[j]);
                    ok = true;
                    break;
                }
                j *= 2;
            }

            if (!ok) {
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