#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    ll a, b;cin >> a >> b;
    ll ans = 0;
    if(b % 2 == 1){
        if(a % 2 == 1){// a * k + b / k 奇数加奇数 = 偶,最大值为a * b + 1
            ans = a * b + 1;
        }else{
            ans = -1;
        }
    }else{//b为偶数, a * k + b / k
        if(a * b / 2 % 2 == 1) ans = -1;
        else ans = a * b / 2 + 2;
    }
    cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--) solve();
}
