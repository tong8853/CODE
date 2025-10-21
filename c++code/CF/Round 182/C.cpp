#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

const int p = 998244353;
void solve(){
    int n;cin >> n;
    vi a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n){
        if(a[i] > b[i]) swap(a[i], b[i]);
    }
    ll ans = 1;
    rep(i, 1, n){//需要非降序排列，如果第i列的小的数大于i-1列的大的数，则第i-1列无法约束到第i列，即出现了一个自由的列
        if(a[i] >= b[i - 1]) ans = (ans * 2LL) % p;
    }
    cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
