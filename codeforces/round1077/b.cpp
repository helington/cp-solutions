#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    string s; cin >> s;
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            total++;
            if (i != 0) s[i-1] = '2';
            if (i != n-1) s[i+1] = '2';
        }
    }

    if (n == 1) {cout << 1 << endl; return;}

    for (int i = 0; i < n; i++) {
        if (s[i] == '1' or s[i] == '2') continue;

        if (i > 0 and s[i - 1] == '0' and s[i] == '0') {
            s[i - 1] = '2';
            s[i] = '1';
            if (i != n-1 and s[i + 1] == '0') s[i+1] = '2';
            total++;
        }

        else if (s[i] == '0' and i != n-1 and s[i + 1] == '0') continue;
        if (s[i] == '0') {
            s[i] = '1';
            total++;
        }
    }

    cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}