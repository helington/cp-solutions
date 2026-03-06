#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve() {
    int n, x, y; cin >> n >> x >> y;

    vector<int> p(n);
    for (auto &it : p) cin >> it;

    deque<int> left_1;
    deque<int> left_2;
    deque<int> right_1;
    deque<int> right_2;

    for (int i = 0; i < x; i++) left_1.push_back(p[i]);
    for (int i = x; i < y; i++) {
        right_1.push_back(p[i]);
        left_2.push_back(p[i]);
    }
    for (int i = y; i < n; i++) right_2.push_back(p[i]);



    while (!right_1.empty() and !left_2.empty() and right_1.front() > left_2.back()) {
        right_1.push_front(left_2.back());
        right_1.pop_back();
        left_2.pop_back();
    }

    while (!left_1.empty() and !right_1.empty() and left_1.back() > right_1.front()) {
        right_2.push_front(left_1.back());
        left_1.pop_back();
    }

    while (!right_1.empty() and !right_2.empty() and right_2.front() < right_1.front()) {
        left_1.push_back(right_2.front());
        right_2.pop_front();
    }

    while (!left_1.empty()) {
        cout << left_1.front() << " ";
        left_1.pop_front();
    }
    while (!right_1.empty()) {
        cout << right_1.front() << " ";
        right_1.pop_front();
    }
    while (!right_2.empty()) {
        cout << right_2.front() << " ";
        right_2.pop_front();
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
}