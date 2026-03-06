#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const int ALPHA = 26;

void solve() {
    string s; cin >> s;
    int n = (int) s.size();

    vector<int> freq(ALPHA, 0);
    for (auto &c : s) freq[c - 'A']++;
    int max_freq = *max_element(freq.begin(), freq.end());

    if (max_freq > (n + 1) / 2) cout << -1 << endl;
    else {
        string ans;
        set<pair<int, char>> st;
        for (int i = 0; i < ALPHA; i++) {
            if (freq[i]) st.insert({freq[i], i + 'A'});
        }
        char past = 'a';

        for (auto &c : s) {
            for (int i = 0; i < ALPHA; i++) {
                if (!freq[i]) continue;
                char curr_c = i + 'A';
                if (curr_c == past) continue;

                auto it = st.find({freq[i], curr_c});
                st.erase(it);

                if (!st.empty()) {
                    auto it2 = st.end(); it2--;
                    if (max(it2->first, freq[i] - 1) > (n) / 2) {
                        st.insert({freq[i], curr_c});
                        continue;
                    }
                }

                ans += curr_c;
                past = curr_c;
                freq[i]--;
                if (freq[i]) st.insert({freq[i], curr_c});
                break;
            }
            n--;
        }

        if (s.size() != ans.size()) cout << -1 << endl;
        else cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}