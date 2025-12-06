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

const int N = 2e5 + 5;
int n;
vi g[N]; //存与u相连的所有节点
ll cnt[N][10];// cnt[u][d]: 以 u 为根时，距离 u 为 d 的节点数
ll ans[N];

void dfs1(int u, int pa){//取u为根节点，计算在该子树中，距离u为d的节点数量（d 0 ~ 9）
    cnt[u][0] = 1;
    for (auto v : g[u]){
        if (v == pa) continue;
        dfs1(v, u);
        rep(d, 1, 9){
            cnt[u][d] += cnt[v][d - 1];
        }
    }
}

void dfs2(int u, int pa){//信息的完善是从上到下的
    ans[u] = cnt[u][9];
    for (auto v : g[u]) {
        if (v == pa) continue;
        ll tmp[10] = {0};
        rep(i, 0, 9) tmp[i] = cnt[v][i];//当前的cnt还只是v做根节点，子树里面距离v为i的节点个数

        //将u的信息传给v
        rep(d, 1, 9) {
            // 从 u 方向来的：距离 u 为 d-1 的点 → 距离 v 为 d
            //u子树包含v子树，所以把u的信息传给v的时候，需要v子树中重复计算的去掉
            if(d >= 2) cnt[v][d] += cnt[u][d - 1] - tmp[d - 2];
            else cnt[v][d] += cnt[u][d - 1];
        }
        dfs2(v, u);
    }
}

void solve(){
    cin>>n;
    rep(i, 1, n-1){
        int u ,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);//dfs1后，只有节点1的信息是完整的，其他节点的信息都是不完整的
    dfs2(1, 0);
    rep(i, 1, n) cout << ans[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}