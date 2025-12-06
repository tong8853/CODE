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

const int N = 2e6 + 5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值
ll f[N];
ll qpow(ll a, ll b){
    ll res = 1;
    a %= p;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

void solve(){
    int n;cin >> n;
    cout << qpow(f[n] + 1, p - 2) % p << " ";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    int cnt = 0;
    rep(i, 1, N - 1){
        int tmp = i;
        while(tmp % 2 == 0) tmp /= 2, cnt++;
        f[i] = cnt;
    }
    while(T--)solve();
}