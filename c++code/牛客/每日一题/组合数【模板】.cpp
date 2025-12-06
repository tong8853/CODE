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

const int N = 5e5;
const ll p = 1e9+7;      // 注意判断 INF 具体的可能值

//预处理阶乘和阶乘逆元
vll f(N + 1);
vll invf(N + 1);

//快速幂
ll qpow(ll a, ll b){
    ll res = 1;
    a %= p;
    while(b > 0){
        if(b & 1) res = res * a % p;
        a = a  * a % p;
        b >>= 1;
    }
    return res % p;
}

void calc(){
    //预处理阶乘
    f[0] = 1;
    rep(i, 1, N) f[i] = f[i - 1] * i % p;

    //预处理逆元
    invf[N] = qpow(f[N], p - 2);
    per(i, N - 1, 0) invf[i] = invf[i + 1] * (i + 1) % p;
}

void solve(){
    int n, m;cin >> n >> m;
    ll ans = (f[m] * invf[n]  % p) * invf[m - n] % p;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    calc();
    int T;cin >> T;
    while(T--)solve();
}