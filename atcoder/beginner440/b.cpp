#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i].first; t[i].second = i + 1;
    }
    sort(t.begin(), t.end());

    for (int i = 0; i < 3; i++) cout << t[i].second << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}