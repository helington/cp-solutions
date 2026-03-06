#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n; cin >> n;

    int m = 0;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        m = max(m, (int) s[i].size());
    }

    for (int i = 0; i < n; i++) {
        int k = m - (int) s[i].size();
        k /= 2;

        for (int j = 0; j < k; j++) cout << '.';
        cout << s[i];
        for (int j = 0; j < k; j++) cout << '.';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}