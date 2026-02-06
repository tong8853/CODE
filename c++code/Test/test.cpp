#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

// 存储关系的结构体
struct Node {
    int u, v, c;
};

// 并查集结构
int fa[2000005]; // 2n 规模，因为 n 条关系最多涉及 2n 个人
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void solve() {
    int n;
    cin >> n;
    vector<Node> ops(n);
    vector<int> nums;

    // 1. 读取数据并收集所有坐标用于离散化
    rep(i, 0, n - 1) {
        cin >> ops[i].u >> ops[i].v >> ops[i].c;
        nums.push_back(ops[i].u);
        nums.push_back(ops[i].v);
    }

    // 2. 离散化过程
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());
    auto get = [&](int x) {
        return lower_bound(all(nums), x) - nums.begin() + 1;
    };

    // 3. 初始化并查集
    int sz = nums.size();
    rep(i, 1, sz) fa[i] = i;

    // 4. 第一遍：处理所有朋友关系 (c == 1)
    rep(i, 0, n - 1) {
        if (ops[i].c == 1) {
            int rootU = find(get(ops[i].u));
            int rootV = find(get(ops[i].v));
            if (rootU != rootV) fa[rootU] = rootV;
        }
    }

    // 5. 第二遍：校验所有敌人关系 (c == 0)
    bool ok = true;
    rep(i, 0, n - 1) {
        if (ops[i].c == 0) {
            if (find(get(ops[i].u)) == find(get(ops[i].v))) {
                ok = false;
                break;
            }
        }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T; // 题目要求处理 T 组案例
    while (T--) solve();
    return 0;
}