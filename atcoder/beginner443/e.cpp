#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

int n;

int di[] = {-1, -1, -1};
int dj[] = {-1, 0, 1};

bool is_valid1(int i, int j) {
    return 0 <= i and i < n and 0 <= j and j < n;
}

bool is_valid2(
    int i, int j, vector<string> &grid,
    vector<vector<bool>> &valid) {
    for (int k = i + 1; k < n; k++) {
        if (valid[k][j]) return true;
        if (grid[k][j] == '#') return false;
    }
    valid[i][j] = true;
    return true;
}

string bfs(
    vector<string> &grid, pair<int, int> start) {

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<bool>> valid(n, vector<bool>(n, false));

    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        for (int k = 0; k < 3; k++) {
            int ni = curr.first + di[k];
            int nj = curr.second + dj[k];

            if (!is_valid1(ni, nj) or visited[ni][nj]) continue;

            if (grid[ni][nj] == '#') {
                if (is_valid2(ni, nj, grid, valid)) {
                    visited[ni][nj] = true;
                    valid[ni][nj] = true;
                    grid[ni][nj] = '.';
                    q.push(make_pair(ni, nj));
                }
            }
            else {
                visited[ni][nj] = true;
                q.push(make_pair(ni, nj));
            }
        }
    }

    string ans = "";
    for (int i = 0; i < n; i++) {
        if (visited[0][i]) ans += '1';
        else ans += '0';
    }

    return ans;
}

void solve() {
    int c; cin >> n >> c;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    string ans = bfs(grid, make_pair(n-1, c-1));

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}