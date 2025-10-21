#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<int> a;
    ll ans = 0;
    int cnt_odd = 0;
    rep(i, 1, n){
        int x;cin >> x;
        if(x % 2 == 0) ans += x;
        else{
            cnt_odd++;
            a.push_back(x);
        }
    }
    if(cnt_odd == 0){
        cout << 0 << endl;
        return;
    }else{
        sort(all(a));
        if(cnt_odd % 2 == 0){
            rep(i, cnt_odd / 2, cnt_odd - 1){
                ans += a[i];
            }
            cout << ans << endl;
        }else{
            rep(i, (cnt_odd - 1) / 2, cnt_odd - 1){
                ans += a[i];
            }
            cout << ans << endl;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
