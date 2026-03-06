#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    string s; cin >> s;

    vector<int> freq(26, 0);
    for (auto c : s) freq[c - 'A']++;

    int odds = 0;
    for (auto &f : freq) if (f % 2 != 0) odds++;

    if (odds > 1) cout << "NO SOLUTION" << endl;
    else {
        string left = "";
        string middle = "";

        for (int i = 0; i < 26; i++) {
            char c = 'A' + i;
            if (freq[i] % 2 != 0) middle = c;

            for (int j = 0; j < freq[i] / 2; j++) left += c;
        }

        string right = left;
        reverse(right.begin(), right.end());

        cout << left << middle << right << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}