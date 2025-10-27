#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MAXN = 105;
int pos[MAXN][MAXN];
void solve(){
    int n, m, k;cin >> n >> m >> k;//m个火把，k个萤石
    rep(i, 1, m){
        int x, y;cin >> x >> y;
        rep(a, -2, 2){
            rep(b, -2, 2){
                if(abs(a) + abs(b) <=2 && (x + a) >= 1 && (x + a) <= n && (y + b) >= 1 && (y + b) <= n){
                    pos[x + a][y + b] = 1;
                }
            }
        }
    }
    rep(j, 1, k){
        int x, y;cin >> x >> y;
        rep(a, x - 2, x + 2){
            if(a >= 1 && a <= n){
                rep(b, y - 2, y + 2){
                    if(b >= 1 && b <= n){
                        pos[a][b] = 1;            
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(i, 1, n) rep(j, 1, n){
        if(pos[i][j] == 0) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}