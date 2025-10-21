#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> children(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;
        children[p].push_back(c);
        // 如果要求孩子按编号升序，最后加一句：
        // sort(children[p].begin(), children[p].end());
    }

    // 对每个节点的孩子排序（如果题目要求字典序/编号序）
    for (int i = 1; i <= n; i++) {
        sort(children[i].begin(), children[i].end());
    }

    int q;
    cin >> q;
    while (q--) {
        int x, i;
        cin >> x >> i;
        if (i <= (int)children[x].size()) {
            cout << children[x][i - 1] << '\n';  // 第 i 个（1-indexed）
        } else {
            cout << "-1\n";  // 或 "NO"
        }
    }

    return 0;
}