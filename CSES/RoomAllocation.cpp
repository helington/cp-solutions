#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<tuple<int, int, int>> values(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        values[i] = {a, b, i};
    }
    sort(values.begin(), values.end());

    int room = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> rooms(n);

    for (int i = 0; i < n; i++) {

        int curr_room = 0;
        if (!pq.empty() and pq.top().first < get<0>(values[i])) {
            curr_room = pq.top().second; pq.pop();
        } else {
            room++; curr_room = room;
        }

        pq.push({get<1>(values[i]), curr_room});
        rooms[get<2>(values[i])] = curr_room;
    }

    cout << room << endl;
    for (auto r : rooms) cout << r << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}