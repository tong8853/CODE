#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

void solve(){
    int k;cin >> k;
    ll ans = 0;
    int a = 0, b = 1;//a是某金币发的天数，b是某天发的金币数
    rep(i, 1, k){
        ans += b;
        a++;
        if(b == a){
            b++;
            a = 0;
        }
    }
    cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;//cin >> T;
	while(T--) solve();
}
