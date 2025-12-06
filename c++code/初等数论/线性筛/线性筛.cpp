#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

const int n = 10e6 + 5;
vi prime;
int a[n];
//核心:一个合数只被其最小质因子筛去
void Init(){
    vi notp(n);
    notp[1] = 1;
    rep(i, 2, n){
        if(!notp[i]) prime.push_back(i);
        for(auto p : prime){
            if((ll) i * p > n) break;
            notp[i * p] = 1;//用p筛去(p * i)这个数
            
            if(i % p == 0) break;//说明p是i的最小质因数，则p是i*p的最小质因数
        }
    }
    for(auto x : prime){
        a[x] = 1;
    }
}

void solve(){
    int x;cin >> x;
    if(a[x] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    Init();
    int T;cin >> T;
	while(T--) solve();
}
