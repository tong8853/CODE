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

PII f[2005];
void solve(){
    int n;cin >> n;
    rep(i, 1, n) cin >> f[i].ff >> f[i].ss;
    sort(f + 1, f + n + 1);
    ll ans = 0;
    rep(i, 1, n){
        rep(j, i, n){
            if(i == j && f[i].ss < 2) continue;
            if(i == j){
                if(f[i].ss >= 3) ans++;
            }else{
                if(f[j].ss >= 2) ans++;
            }
            //i != j || i == j && f[i].ss == 2
            //现在要找到最后最后一个小于f[i] + f[j]的元素,方便统计有多少种符合条件的
            int tar_x = f[i].ff + f[j].ff;
            PII tar = {tar_x, -1};
            int cnt = lower_bound(f + j + 1, f + n + 1, tar) - (f + j + 1);
            ans += cnt;
            
        }
    }
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}