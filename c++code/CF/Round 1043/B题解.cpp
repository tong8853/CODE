#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

//答案为x, 加k个0变成y, y = x * 10 ** k, n = x + y = (10**k + 1) * x
// 因为11 <= n <= 10 ** 18, 所以 1 <= k <= 17
//可以得到x == n / (10**k + 1),枚举每一个k，看是否能得到对应的x

void solve(){
    ll r; cin >> r;
    ll d = 11;
    vector<ll> ans;
    int cnt = 0;
    while(r >= d){
        if(r % d == 0){
            ans.push_back(r / d);
            cnt++;
        }
        d = (d - 1) * 10 + 1;
    }

    cout << cnt << endl;
    per(i, cnt - 1, 0){
        cout << ans[i] << " ";
    }
    if(cnt != 0) cout << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
