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
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
    }
    cout << qpow(2, n - 1) << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--) solve();
}
