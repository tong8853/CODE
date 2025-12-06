#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n;cin >> n;
    vi a(n);
    rep(i, 0, n - 1){
        cin >> a[i];
    }
    ll ans;
    sort(all(a));
    int MEX = 0;
    rep(i, 0, n - 1){
        if(a[i] == MEX) MEX++;
    }
    ans = a[n - 1] - MEX;
    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
