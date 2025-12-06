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

char g[105][105];
PII f[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
bool dfs(int x, int y){
    if(x == n && y == m && g[x][y] == '.') return true;
    //若合法，标记为已走，继续向下dfs,否则返回false,即此路不通
    if(x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] == '.') g[x][y] = '#';
    else return false;
    rep(i, 0, 3){
        int nx = x + f[i].ff;
        int ny = y + f[i].ss;
        if(dfs(nx, ny)) return true;
    }
    return false;
}

void solve(){
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m)cin >> g[i][j];
    cout << (dfs(1, 1) ? "Yes" : "No") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}