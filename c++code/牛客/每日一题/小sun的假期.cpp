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


void solve(){
    int n, m;cin >> n >> m;
    int l, r;
    vector<PII> a;
    rep(i, 1, m){
        cin >> l >> r;
        a.push_back({l, r});
    }
    sort(all(a));
    int ans = 0;
    int lr = a[0].ss;
    rep(i, 1, m - 1){
        if(a[i].ff > lr){
            ans = max(ans, a[i].ff - lr - 1);
        }
        lr = max(lr, a[i].ss);
    }
    ans = max(ans, a[0].ff - 1);
    ans = max(ans, n - lr);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}