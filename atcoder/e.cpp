#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ld> angles;
    vector<ld> saved_angles(n + 1);

    for (int i = 1; i <= n; i++) {
        ld x, y;
        cin >> x >> y;

        ld angle = atan2(y, x);
        angle = angle * (-1.0);

        angles.push_back(angle);
        saved_angles[i] = angle;
    }
    sort(angles.begin(), angles.end());

    while (q--) {
        int a, b;
        cin >> a >> b;

        ld angA = saved_angles[a];
        ld angB = saved_angles[b];

        ll count = 0;

        if (angA <= angB) {

            auto it1 = lower_bound(angles.begin(), angles.end(), angA);
            auto it2 = upper_bound(angles.begin(), angles.end(), angB);

            count = (it2 - it1);
        }
        else {
            auto it1 = lower_bound(angles.begin(), angles.end(), angA);
            count += (angles.end() - it1);

            auto it2 = upper_bound(angles.begin(), angles.end(), angB);
            count += (it2 - angles.begin());
        }

        cout << count << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}