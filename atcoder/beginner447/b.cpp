#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    string s; cin >> s;

    vector<int> freq(26, 0);
    for (auto &c : s) freq[c - 'a']++;

    int max_freq = *max_element(freq.begin(), freq.end());

    for (auto &c : s) {
        if (freq[c - 'a'] != max_freq) cout << c;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}