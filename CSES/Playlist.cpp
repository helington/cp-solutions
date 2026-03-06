#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >>a[i];

    int l = 0, r = 0;
    int ans = 0;
    set<int> s;

    while (r < n) {
        if (!s.count(a[r])) {
            s.insert(a[r]);
            r++;
        }
        else {
            s.erase(a[l]);
            l++;
        }

        ans = max(ans, r - l);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}