#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

int n; int m;

bool is_valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

pair<int, vector<vector<pair<int, int>>>> bfs(
    vector<string> labyrinth, pair<int, int> start, pair<int, int> end
    ) {
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[start.first][start.second] = 0;

    queue<pair<int, int>> q;
    q.push(start);

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    parent[start.first][start.second] = {-1, -1};

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (is_valid(ni, nj) && dist[ni][nj] == -1 && labyrinth[ni][nj] != '#') {
                dist[ni][nj] = dist[i][j] + 1;
                parent[ni][nj] = {i, j};
                q.push({ni, nj});
            }
        }
    }

    return {dist[end.first][end.second], parent};
}

char compute_step(int i, int j, int parent_i, int parent_j) {
    if (parent_i < i) return 'D';
    if (parent_i > i) return 'U';
    if (parent_j < j) return 'R';
    if (parent_j > j) return 'L';
}

void solve() {
    cin >> n >> m;

    vector<string> labyrinth(n);
    for (int i = 0; i < n; i++) cin >> labyrinth[i];

    pair<int, int> start, end;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (labyrinth[i][j] == 'A') start = {i, j};
        else if (labyrinth[i][j] == 'B') end = {i, j};
    }

    auto [dist, parent] = bfs(labyrinth, start, end);

    if (dist == -1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << dist << endl;

        pair<int, int> current = make_pair(end.first, end.second);
        string path = "";
        while (parent[current.first][current.second] != make_pair(-1, -1)) {
            path += compute_step(
                current.first, current.second, parent[current.first][current.second].first, parent[current.first][current.second].second
            );
            current = parent[current.first][current.second];
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}