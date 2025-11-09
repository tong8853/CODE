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

int n, m, q;
const int MAXN = 1005;
int a[1005][1005];
ll b[1005][1005];
void solve(){
    cin >> n >> m >> q;
    rep(i, 1, n) rep(j, 1, m)cin >> a[i][j];
    rep(i, 1, n)rep(j, 1, m) b[i][j] = b[i - 1][j] + b[i][j - 1] + a[i][j] - b[i - 1][j - 1];
    while(q--){
        int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
        cout << b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}