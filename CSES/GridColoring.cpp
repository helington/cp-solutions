#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

int n, m;

bool is_valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool get_final_grid(vector<vector<char>> &final_grid, vector<string> &grid) {
    vector<vector<vector<bool>>> possible(n, vector<vector<bool>>(m, vector<bool>(4, true)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            possible[i][j][grid[i][j] - 'A'] = false;

            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];

                if (is_valid(ni, nj) and final_grid[ni][nj] != 'E') possible[i][j][final_grid[ni][nj] - 'A'] = false;
            }

            bool atribuited = false;
            for (int k = 0; k < 4; k++) if (possible[i][j][k]) {
                final_grid[i][j] = 'A' + k;
                atribuited = true; break;
            }

            if (!atribuited) return false;
        }
    }

    return true;
}

void solve() {
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0 ; i < n; i++) cin >> grid[i];

    vector<vector<char>> final_grid(n, vector<char>(m, 'E'));

    bool possible = get_final_grid(final_grid, grid);

    if (!possible) cout << "IMPOSSIBLE" << endl;
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << final_grid[i][j];
            cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}