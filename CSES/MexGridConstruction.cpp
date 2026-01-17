#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, -1));
    for (int i = 1; i < n; i++) {
        grid[0][i] = i;
        grid[i][0] = i;
        grid[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == -1) {
                vector<bool> values(n * n, false);
                for (int k = 0; k < i; k++) values[grid[k][j]] = true;
                for (int k = 0; k < j; k++) values[grid[i][k]] = true;

                int mex = 0;
                while (values[mex]) mex++;
                grid[i][j] = mex;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}