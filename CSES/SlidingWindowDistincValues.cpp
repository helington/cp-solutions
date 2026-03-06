#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto all = a;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    vector<int> freq(all.size(), 0);

    int window = 0;
    for (int i = 0; i < k; i++) {
        int idx = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
        freq[idx]++;
        if (freq[idx] == 1) window++;
    }

    cout << window << " ";

    for (int l = 0, r = k; r < n; r++, l++) {
        int remove = lower_bound(all.begin(), all.end(), a[l]) - all.begin();
        int add = lower_bound(all.begin(), all.end(), a[r]) - all.begin();

        freq[remove]--;
        if (freq[remove] == 0) window--;

        freq[add]++;
        if (freq[add] == 1) window++;

        cout << window << " ";
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}