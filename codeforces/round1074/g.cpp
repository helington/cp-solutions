#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

const int INF = 1e9 + 10;

void solve() {
    int n; cin >> n;

    vector<int> mex_vec(n);
    int total_mex = 0;

    vector<vector<int>> vectors(n);

    for (int i = 0; i < n; i++) {
        int l; cin >> l;

        vector<int> vec(l);
        for (int i = 0; i < l; i++) cin >> vec[i];
        vectors.push_back(vec);

        vector<bool> used(l+1, false);
        for (int i = 0; i < l; i++) used[vec[i]] = true;

        int mex = 0;
        while (used[mex]) mex++;

        total_mex += mex;
        mex_vec[i] = mex;
    }

    vector<vector<int>> mex_without_i_j(n, vector<int>(n, total_mex));
    for (int i = 0; i < n; i++)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}