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
const ll INF = 1e15, p = 1e9 + 7;       // 注意判断 INF 具体的可能值

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
void solve(){
    int n, m;cin >> n >> m;
    ll a = 1, b = 1, c = 1;
    rep(i, 1, n) a = a * i % p;
    rep(i, 1, m) b = b * i % p;
    b = qpow(b, p - 2);
    rep(i, 1, n - m) c = c * i % p;
    c = qpow(c, p - 2);
    cout << a * b % p * c % p;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}