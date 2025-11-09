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

char a[600][600];
int n, m;

void dfs(int x, int y){
    if(x <= 0 || x > n || y <= 0 || y > m || a[x][y] == '*') return;
    
    a[x][y] = '*';
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

void solve(){
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    //从四周灌洪水
    rep(i, 1, n){//左右两边
        dfs(i, 1);
        dfs(i, m);
    }
    rep(j, 1, m){//上下两边
        dfs(1, j);
        dfs(n, j);
    }
    int ans = 0;
    rep(i, 1, n) rep(j, 1, m){
        if(a[i][j] == '0') ans++;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}