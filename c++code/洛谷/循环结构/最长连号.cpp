#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
    }
    int cnt = 1;
    int ans = 0;
    rep(i, 2, n){
        if(a[i] == a[i - 1] + 1) cnt++;
        else cnt = 1;
        if(cnt > ans) ans = cnt;
    }
    cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
