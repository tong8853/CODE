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

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, mod = 998244353;       // 注意判断 INF 具体的可能值

void solve(){
    int n, m;cin >> n >> m;
    vector<vector<PII>> g(n + 1);//g[u]存{u, w}
    rep(i, 0 ,m - 1){
        int u, v, w;cin >> u >> v >> w;
        g[u].pb(PII(v, w));
        g[u].pb(PII(u, w));
    }

    vector<bool> vis (n + 1, false); //标记节点是否加入
    priority_queue<PII, vector<PII>, greater<PII>> pq;//小根堆：{边权， 节点}
    pq.push({0, 1}); //从节点一开始，代价为0
    ll ans = 0;//MST的总权重
    int cnt = 0;//已加入的节点
    while(pq.size()){
        auto [w, u] = pq.top();
        pq.pop();

        if(vis[u]) continue;//已经访问过，跳过
        vis[u] = true;
        ans += w;
        cnt++;

        //遍历u的所有邻接点， 将未访问过的加入到堆
        for(auto [v, w2] : g[u]){
            if(!vis[v]) pq.push(PII(w2, v));
        }
    }

    //如果MST包含所有n个节点，则图联通
    if(cnt == n) cout << ans << endl;
    else cout << "orz" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}