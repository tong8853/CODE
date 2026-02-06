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
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

ll pow(ll a, ll b){
    ll res = 1;
    a %= p;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll inv(ll x){
    return pow(x, p - 2);
}

struct lr{
    ll l, r, len;
};

inline void solve(){
    int n;cin >> n;
    vector<lr> a(n);
    rep(i, 0, n - 1){
        cin >> a[i].l >> a[i].r;
        a[i].len = a[i].r - a[i].l + 1;
    }

    ll ans = n;
    rep(i, 1, n - 1){
        ll L = max(a[i - 1].l, a[i].l);
        ll R = min(a[i - 1].r, a[i].r);

        if(L <= R){//有交集
            ll len = R - L + 1;
            ll c = (len % p) * inv(a[i - 1].len % p) % p * inv(a[i].len % p) % p;
            ans = (ans - c + p) % p;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}