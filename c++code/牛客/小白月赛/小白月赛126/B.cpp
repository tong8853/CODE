#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(int l, int r, T &a){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

inline void solve(){
    int n;cin >> n;
    vi a(n);
    read(0, n - 1, a);
    sort(all(a));
    ll ans = 0;
    int maxx = 0;
    rep(i, 0, n - 1){
        if(i == 0){
            ans += a[i] - a[n - 1] + 8;
            maxx = a[i] - a[n - 1] + 8;
        }else{
            ans += a[i] - a[i - 1];
            maxx = max(maxx, a[i] - a[i - 1]);
        }
    }
    cout << ans - maxx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}