#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int q; cin >> q;

    int vol = 0; bool playing = false;
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        bool flag = false;

        if (op == 1) vol++;
        else if (op == 2 and vol > 0) vol--;
        else if (op == 3) playing = !playing;

        if (vol >= 3 and playing) flag = true;

        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}