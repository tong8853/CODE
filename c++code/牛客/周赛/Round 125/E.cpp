#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;

const int N = 3e5 + 5;

struct Node {
    ll sum;
    int min_val;
    int lazy; // 区间覆盖标记，-1 表示无标记
} tree[N << 2];

int a[N];

void push_up(int p) {
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    tree[p].min_val = min(tree[p << 1].min_val, tree[p << 1 | 1].min_val);
}

void apply(int p, int l, int r, int v) {
    tree[p].sum = (ll)(r - l + 1) * v;
    tree[p].min_val = v;
    tree[p].lazy = v;
}

void push_down(int p, int l, int r) {
    if (tree[p].lazy != -1) {
        int mid = (l + r) >> 1;
        apply(p << 1, l, mid, tree[p].lazy);
        apply(p << 1 | 1, mid + 1, r, tree[p].lazy);
        tree[p].lazy = -1;
    }
}

void build(int p, int l, int r) {
    tree[p].lazy = -1;
    if (l == r) {
        tree[p].sum = tree[p].min_val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

void update_set(int p, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
        apply(p, l, r, v);
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) update_set(p << 1, l, mid, ql, qr, v);
    if (qr > mid) update_set(p << 1 | 1, mid + 1, r, ql, qr, v);
    push_up(p);
}

int query_min(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p].min_val;
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    int res = 2e9; // 初始为无穷大
    if (ql <= mid) res = min(res, query_min(p << 1, l, mid, ql, qr));
    if (qr > mid) res = min(res, query_min(p << 1 | 1, mid + 1, r, ql, qr));
    return res;
}

inline void solve() {
    int n, q; cin >> n >> q;
    rep(i, 1, n) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            int v = query_min(1, 1, n, 1, x);
            update_set(1, 1, n, 1, x, v);
        } else if (op == 2) {
            int y; cin >> y;
            int v = query_min(1, 1, n, y, n);
            update_set(1, 1, n, y, n, v);
        } else {
            cout << tree[1].sum << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}