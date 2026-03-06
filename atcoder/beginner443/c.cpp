#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, end; cin >> n >> end;

    vector<int> a;
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            int value; cin >> value;
            a.emplace_back(value);
        }
    }
    else { a.push_back(end); n++; }

    if (a[n-1] != end) {
        a.push_back(end);
        n++;
    }

    int ans = 0;
    int current_open = 0;

    while (true) {
        auto it = lower_bound(a.begin(), a.end(), current_open);

        if (it == a.end()) break;

        ans += *it - current_open;
        current_open = *it + 100;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}