#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int di[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dj[] = {1, -1, 1, -1, 2, -2, 2, -2};

int n;

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

vector<vector<int>> bfs() {
    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[0][0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();

        for (int k = 0; k < 8; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (is_valid(ni, nj) and dist[ni][nj] == -1) {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    return dist;
}

void solve() {
    cin >> n;

    auto dist = bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << dist[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}