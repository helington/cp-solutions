#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const int ALPHA = 26;
const char NORM = 'a';

struct Node {
    vector<int> nxt;
    int pref;

    Node() : nxt(ALPHA, 0), pref(0) {}
};

struct Trie {
    vector<Node> nodes;

    Trie() { nodes.emplace_back(); }

    void insert(string &s) {
        int curr = 0;

        for (auto &c : s) {
            int idx = c - NORM;

            if (!nodes[curr].nxt[idx]) {
                nodes[curr].nxt[idx] = (int) nodes.size();
                nodes.emplace_back();
            }

            curr = nodes[curr].nxt[idx];
            nodes[curr].pref++;
        }
    }

    int find_node(string &s) {
        int curr = 0;

        for (auto &c : s) {
            int idx = c - NORM;
            if (!nodes[curr].nxt[idx]) return -1;
            curr = nodes[curr].nxt[idx];
        }

        return curr;
    }

    int query(string &s) {
        int idx = find_node(s);
        return idx != -1 ? nodes[idx].pref : 0;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    Trie trie;

    while (n--) {
        string s; cin >> s;
        trie.insert(s);
    }

    while (q--) {
        string s; cin >> s;
        cout << trie.query(s) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}