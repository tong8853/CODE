#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=(a); i <=(b); i++)
#define QAQ(x) cout<<#x<<": "<<(x)<<endl, exit(0);
#define endl '\n'
#define int long long
using namespace std;		// int => long long
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, mod = 998244353;		// 注意判断 INF 具体的可能值

int n, m;

int a[N];
int ans[N],  cnt[N][10];
vector<int> g[N];

void dfs1(int u, int pa){
    cnt[u][0] = 1;
    for(auto v : g[u]){
        if(v == pa) continue;
        
        dfs1(v, u);
        for(int i=1; i <= 9; ++i){
            cnt[u][i] += cnt[v][i-1];
        }
    }
}

void dfs2(int u, int pa){
    ans[u] = cnt[u][9];
    for(auto v : g[u]){
        if(v == pa) continue;
        int tmp[10] = {0};
        REP(i, 0, 9) tmp[i] = cnt[v][i];
        REP(i, 1, 9){
            cnt[v][i] += cnt[u][i-1] - (i>=2 ?tmp[i-2] :0);
        }
        dfs2(v, u);
    }
}

void solve(){
    cin>>n;
    REP(i, 1, n-1){
        int u ,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    // REP(i, 1, n) cerr<<cnt[i][1]<<endl;
    dfs2(1, 0);
    ans[1] = cnt[1][9];
    REP(i, 1, n) cout<<ans[i]<<' ';
}


signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--){
        solve();
    }
    return 0;
}