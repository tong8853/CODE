#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

void solve(){
    ll n;cin >> n;
    ll px = 1;//3^0,px¶ÔÓ¦3^x
    ll ans = 0;
    for(int x = 0; n > 0; x++){
        while(n % 3){
            n--;
            ans += (3 * px + x * (px / 3)); //3^(x + 1) + x * 3^(x - 1)
        }
        n /= 3;
        px *= 3;
    }
    cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
