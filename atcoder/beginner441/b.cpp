#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    vector<bool> takashi_chars(26, false);
    for (int i = 0; i < n; i++) takashi_chars[s[i] - 'a'] = true;

    vector<bool> aoki_chars(26, false);
    for (int i = 0; i < m; i++) aoki_chars[t[i] - 'a'] = true;

    int q; cin >> q;

    while (q--) {
        bool takashi = true, aoki = true;

        string w; cin >> w;

        for (int i = 0; i < w.size(); i++) {
            if (!takashi_chars[w[i] - 'a']) takashi = false;
            if (!aoki_chars[w[i] - 'a']) aoki = false;
        }

        if (takashi and !aoki) cout << "Takahashi" << endl;
        else if (!takashi and aoki) cout << "Aoki" << endl;
        else cout << "Unknown" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}