#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

const int p = 998244353;
ll qpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans;
}
void solve(){
    int n;cin >> n;
    int cnt_1 = 0;
    rep(i, 1, n){
        int x;cin >> x;
        if(x & 1) cnt_1++;
    }
    ll tot = (qpow(2, n) - 1 + p) % p;
    ll odd = (qpow(2, cnt_1) - 1 + p) % p;
    cout << (tot - odd + p) % p << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--) solve();
}
