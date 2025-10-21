#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

//核心:一个合数只被其最小质因子筛去
void solve(){
    int n, q; cin >> n >> q;
    vi notp(n + 1);
    vi prime;
    notp[1] = 1;
    rep(i, 2, n){
        if(!notp[i]) prime.push_back(i);
        for(auto p : prime){
            if((ll) i * p > n) break;
            notp[i * p] = 1;//用p筛去(p * i)这个数
            
            if(i % p == 0) break;//说明p是i的最小质因数，则p是i*p的最小质因数
        }
    }
    while(q--){
        int k;cin >> k;
        cout << prime[k - 1] << endl;
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
