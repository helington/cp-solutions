#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

int n;

bool Comp (const int mask1, const int mask2) {
    int total1 = 0, total2 = 0;

    for (int i = 0; i < (1 << n); i++) {
        int bit1 = mask1 & (1 << i), bit2 = mask2 & (1 << i);
        total1 += bit1;
        total2 += bit2;

        if (!bit1 or !bit2) break;
    }

    if (total1 != total2) return total1 > total2;
    return mask1 < mask2;
}

void solve() {
    cin >> n;

    vector<int> ans(1 << n);

    for (int i = 0; i < (1 << n); i++) ans[i] = i;
    sort(ans.begin(), ans.end(), Comp);

    for (auto &it : ans) cout << it << " ";
    cout << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}