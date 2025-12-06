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

const ll p = 998244353;
ll qpow(ll a, ll b){
    ll res = 1;
    a %= p;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T, N;cin >> T >> N;
    ll ans = 0;
    vll f(N + 1), invf(N + 1);
    f[0] = 1;
    rep(i, 1, N) f[i] = f[i - 1] * i %p;
    invf[N] = qpow(f[N], p - 2);
    per(i, N - 1, 0) invf[i] = invf[i + 1] * (i + 1) % p;
    while(T--){
        ll n, m;cin >> n >> m;
        ans ^= (f[n] * invf[m] % p * invf[n - m] % p);
    }
    cout << ans << endl;
}