#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<int> a(n), b(n);
    ll ans = 0;
    rep(i, 0, n - 1) cin >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));
    rep(i, 0, n - 1){
        ans += b[i] - a[i];
        if(i < n - 1){
            if(b[i] > a[i + 1]){
                ans -= b[i] - a[i + 1];
            }
        }
    }
    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
