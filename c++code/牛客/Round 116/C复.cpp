#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

struct node {
    int l;
    int r;
    int j;
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<node> a(n);
    rep(i, 0, n - 1) {
        cin >> a[i].l >> a[i].r;
        a[i].j = i + 1;
    }

    auto cmp = [&](node w, node e) {
        return w.l < e.l;
    };
    sort(all(a), cmp);

    vi b(n), c(n);
    rep(i, 0, n - 1) {
        b[i] = a[i].l;
        c[i] = a[i].r;
    }

    while (q--) {
        int x;
        cin >> x;

        auto it1 = upper_bound(all(b), x); // 第一个大于 x 的位置
        int pos = it1 - b.begin();

        if (pos == 0) {
            cout << -1 << endl;
        } else {
            pos--; // 最后一个左端点 <= x 的区间
            if (c[pos] >= x) {
                cout << a[pos].j << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while (T--) solve();
}