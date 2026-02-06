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

inline void solve(){
    int n;cin >> n;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int i = 1;
    int cnt = 0;
    ll ans = 0;
    while(i != n + 1){
        //判断i~r是否为一个基本单元
        int r = i + a[i] - 1;
        if(r > n){
            i++;
            continue;
        }
        bool ok = true;
        rep(j, i, r){
            if(a[j] != a[i]){
                ok = false;
                break;
            }
        }

        if(ok){
            cnt++;
            i = r + 1;
        }else{
            ans += (1LL * cnt * (cnt + 1) / 2);
            cnt = 0;
            i++;
        }
    }
    ans += (1LL * cnt * (cnt + 1) / 2);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}