#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(){
    int n;cin >> n;
    vi a(n);
    rep(i, 0, n - 1){
        cin >> a[i];
    }
    sort(all(a));
    vi b, c;
    rep(i, 0, n - 2) b.pb(a[i]);
    rep(i, 1, n - 1) c.pb(a[i]);
    ll ans1 = 0, ans2 = 0;
    for(auto &x : b) ans1 += abs(b[(n-1) >> 1] - x);
    for(auto &x : c) ans2 += abs(c[(n-1) >> 1] - x);
    cout << min(ans1, ans2) << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
