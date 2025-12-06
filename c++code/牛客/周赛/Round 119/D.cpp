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

ll qpow(ll a, ll b){
    a %= p;
    ll ans = 1;
    while(b != 0){
        if(b & 1) ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans % p;
}

void solve(){
    int n;cin >> n;
    ll k;cin >> k;
    int cnt = 0;
    rep(i, 1, n){
        int x;cin >> x;
        if(i % 2) cnt += x;
        else cnt -= x;
        while(cnt < 0 && k > 0){
            k >>= 1;
            cnt++;
        }
        if(cnt < 0){//说明k提前等于0了
            cnt = 0;
        }
    }
    cout << k % p * qpow(2, cnt) % p << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}