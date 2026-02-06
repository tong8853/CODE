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
const ll INF = 1e15, p = 1e9 + 7;       // 注意判断 INF 具体的可能值

ll qpow(ll a, ll b){
    a %= p;
    ll res = 1;
    while(b){
        if(b & 1){
            res = res * a % p;
        }
        a = a * a % p;
        b = b >> 1;
    }
    return res;
}
inline void solve(){
    ll n;cin >> n;
    cout << qpow(2, n / 2) % p << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}