#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

const int MAXN = 2e5+1;

void solve() {
    int n; cin >> n;

    vector<ll> ones(MAXN, 0);
    vector<ll> a(n);
    ll max_one = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ones[a[i]-1]++;
        max_one = max(max_one, a[i]-1);
    }

    string ans = "";

    ll curr_ones = n; ll to_add = 0; ll remaining = 0;
    for (int i = 0; i <= max_one; i++) {
        to_add = remaining + curr_ones;
        remaining = (to_add / 10); to_add = to_add % 10;
        ans += (to_add + '0');
        curr_ones -= ones[i];
    }

    while (remaining) {
        to_add = remaining % 10; remaining /= 10;
        ans += (to_add + '0');
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}