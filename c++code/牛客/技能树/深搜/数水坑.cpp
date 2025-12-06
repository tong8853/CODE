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
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

int n, m;
char g[105][105];
PII d[8] = {{0,1}, {0,-1}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
void dfs(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(g[x][y] == '.') return;
    if(g[x][y] == 'W') g[x][y] = '.';
    rep(i, 0, 7){
        int nx = x + d[i].ff;
        int ny = y + d[i].ss;
        dfs(nx, ny);
    }
}

void solve(){
    cin >> n >> m;
    int ans = 0;
    rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
    rep(i, 1, n) rep(j, 1, m){
        if(g[i][j] == 'W'){
            ans++;
            dfs(i, j);
        } 
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}