#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    int n;cin >> n;
    vector<char> a(n);
    int cnt = 0, ans = 0;
    rep(i, 0, n - 1){
        cin >> a[i];
        if(a[i] == '1') cnt++;
    }
    rep(i, n - cnt, n - 1){
        if(a[i] == '0') ans++;
    }
    cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--) solve();
}
