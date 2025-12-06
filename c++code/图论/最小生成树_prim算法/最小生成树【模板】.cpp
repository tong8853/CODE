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

const int N = 2e5 + 5, M = 1e6 + 5;
const ll INF = 1e15, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    // 建邻接表：g[u] 存 {v, 边权}
    vector<vector<PII>> g(n + 1);
    rep(i, 0, m - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb(PII(v, w));
        g[v].pb(PII(u, w)); // 无向图，双向加边
    }

    vector<bool> vis(n + 1, false);               // 标记节点是否已加入 MST
    priority_queue<PII, vector<PII>, greater<PII>> pq; // 小根堆：{边权, 节点}
    pq.push({0, 1});                              // 从节点 1 开始，初始代价为 0

    ll ans = 0;   // MST 总权重
    int cnt = 0;  // 已加入 MST 的节点数

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;  // 已访问过，跳过
        vis[u] = true;         // 标记加入 MST
        ans += w;
        cnt++;

        // 遍历 u 的所有邻接点，将未访问的点加入堆
        for (auto [v, w2] : g[u]) {
            if (!vis[v]) {
                pq.push({w2, v});
            }
        }
    }

    // 如果 MST 包含所有 n 个节点，则图连通
    if (cnt == n) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl; // 图不连通
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while (T--) solve();
}