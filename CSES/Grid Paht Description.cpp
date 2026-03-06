#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

int m = 48;
bool vis[9][9];

int compute_dir(char c) {
    if (c == 'D') return 0;
    if (c == 'U') return 1;
    if (c == 'R') return 2;
    return 3;
}

ll backtracking(const string &s, int idx, int i, int j) {
    if (i == 7 && j == 1) {
        if (idx == m) return 1;
        return 0;
    }
    if (idx == m) return 0;

    if (vis[i][j - 1] and vis[i][j + 1] and !vis[i - 1][j] and !vis[i + 1][j]) {
        return 0;
    }

    if (vis[i - 1][j] and vis[i + 1][j] and !vis[i][j - 1] and !vis[i][j + 1]) {
        return 0;
    }

    ll ans = 0;
    vis[i][j] = true;

    if (s[idx] == '?') {
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (!vis[ni][nj]) {
                ans += backtracking(s, idx + 1, ni, nj);
            }
        }
    } else {
        int k = compute_dir(s[idx]);
        int ni = i + di[k];
        int nj = j + dj[k];
        if (!vis[ni][nj]) {
            ans += backtracking(s, idx + 1, ni, nj);
        }
    }

    vis[i][j] = false;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 9; i++) {
        vis[0][i] = true;
        vis[8][i] = true;
        vis[i][0] = true;
        vis[i][8] = true;
    }

    string s; cin >> s;
    cout << backtracking(s, 0, 1, 1) << endl;

    return 0;
}