#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1){
        cin >> a[i];
    }
    ll ans = -1e9;
    rep(i, 0, n - 2){
        ll ma = max(a[i], a[i + 1]);
        ll me = 0;
        if(a[i] + a[i + 1] == 1) me = 2;
        else if(a[i] == 0 || a[i + 1] == 0) me = 1;
        ans = max(ma - me, ans);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}