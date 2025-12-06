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
    int n, k;cin >> n >> k;
    string s;cin >> s;
    vector<PII> a;
    int m = 0;
    rep(i, 0, n - 1){
        if(s[i] == '1'){
        a.push_back({i, min(i + k, n - 1)});
        m++;
        }
    }
    if(m == 0) cout << n << endl;
    else{
        sort(all(a));
        ll ans = 0;
        ans += a[0].ff;
        ans += n - 1 - a[m - 1].ss;
        int r = a[0].ss;
        rep(i, 1, m - 1){
            if(a[i].ff > r) ans += a[i].ff - r -1;
            r = max(r, a[i].ss);
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}