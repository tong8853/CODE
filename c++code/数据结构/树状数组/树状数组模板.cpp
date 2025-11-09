#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MAXN = 100010;  // 根据题目需求调整

// 全局数组
vi a;        // 原数组，1-indexed
vll b;       // 树状数组（BIT），1-indexed

inline int lowbit(int x) {
    return x & (-x);
}

// 查询前缀和 [1, i]
ll query(int i) {
    ll s = 0;
    while (i > 0) {
        s += b[i];
        i -= lowbit(i);
    }
    return s;
}

// 单点更新：a[i] += x
void update(int i, ll x) {
    while (i <= b.size()) {
        b[i] += x;
        i += lowbit(i);
    }
}

// 初始化树状数组
void init(const vi& arr) {
    int n = arr.size() - 1;  // arr[1..n]
    a = arr;
    b.assign(n + 1, 0);  // 初始化树状数组为 0

    // 构建树状数组：对每个元素进行 update
    rep(i, 1, n) {
        update(i, a[i]);
    }
}

// 如果需要从 0-indexed 数组初始化，可以这样：
void init_from_0index(const vi& arr0) {
    int n = arr0.size();
    vi arr(n + 1);
    rep(i, 1, n) {
        arr[i] = arr0[i - 1];
    }
    init(arr);
}

void solve() {
    int n, q;
    cin >> n >> q;  // n: 元素个数, q: 查询次数

    // 读入原数组（1-indexed）
    vi arr(n + 1);
    rep(i, 1, n) {
        cin >> arr[i];
    }

    // 初始化树状数组
    init(arr);

    // 处理 q 次操作
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            // 单点修改：将第 i 个元素增加 x
            int i, x;
            cin >> i >> x;
            update(i, x);
        } else if (op == 2) {
            // 查询前缀和 [1, i]
            int i;
            cin >> i;
            cout << query(i) << endl;
        } else if (op == 3) {
            // 查询区间和 [l, r]
            int l, r;
            cin >> l >> r;
            cout << query(r) - query(l - 1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}