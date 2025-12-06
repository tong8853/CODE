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
vi g[N]; //g[i]表示与i相连的所有节点
int L[N]; //L[i]表示节点i到叶子节点的最短距离
vector<bool> ok(N);
void dfs(int u, int pa){
    if(ok[u] = 1){
        L[u] = 
    }  
}

void solve(){
    cin >> n;
    int a, b;cin >> a >> b;
    rep(i, 1, n - 1){
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    rep(i, 1, n){
        if(g[i].size() <= 1){
            ok[i] = 1;
        }else ok[i] = 0;
    }



}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T ;cin >> T;
    while(T--)solve();
}