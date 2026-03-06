#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n, m, k;cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());

    int j = 0; int count = 0;
    for (int i = 0; i < n and j < m; i++) {
        while (j < m and b[j] < a[i] - k) {
            j++;
        }
        if (b[j] >= a[i] - k and b[j] <= a[i] + k) {
            j++;
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}