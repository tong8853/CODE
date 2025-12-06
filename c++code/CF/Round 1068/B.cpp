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

const int N = 1e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值


void solve(){
    int n;cin >> n;
    vi a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    ll minx = min(b[1], -a[1]), maxx = max(b[1], -a[1]);
    rep(i, 2, n){
        ll minxx = minx;
        ll maxxx = maxx;
        minx = min(b[i] - maxxx, minxx - a[i]);
        maxx = max(b[i] - minxx, maxxx - a[i]);
    }
    cout << maxx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}