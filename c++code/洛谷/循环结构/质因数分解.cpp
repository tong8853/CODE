#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

bool isZhi(int x){
    if(x == 1) return false;
    if(x == 2) return true;
    rep(i, 2, (int)sqrt(x)){
        if(x % i == 0) return false;
    }
    return true;
}

void solve(){
    ll n;cin >> n;
    rep(i, 2, (int)sqrt(n)){
        if(n % i == 0 && isZhi(i)){
            cout << n / i << endl; 
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
