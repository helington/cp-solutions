#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
 
int n; int t;
 
bool check(vector<int> &k, const int m) {
    int total = 0;
    for (int i = 0; i < k.size(); i++) {
        total += m / k[i];
        if (total >= t) return true;
    }
    return false;
}
 
void solve() {
    cin >> n >> t;
 
    vector<int> k(n);
    for (int i = 0 ; i < n; i++) cin >> k[i];
 
    int l = 1, r = 1e18; int m;
 
    while (l <= r) {
        m = l + (r - l) / 2;
        if (check(k, m)) r = m - 1;
        else l = m + 1;
    }
 
    cout << r + 1 << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}