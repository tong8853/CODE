#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

//b的二进制表示是bnbn-1....b0, bi取值1或0, b = 对2^
//a^b = a^b0 * a^b2 * ... * a^bn
ll qpow(ll a, ll b, ll p){
    ll ans = 1;
    while(b){//如果当b为二进制为1就要乘上这个数
        if(b & 1) ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans;
}

void solve(){
    
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
}
