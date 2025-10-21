#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i] >> b[i];
    int x = *max_element(all(a)) - *min_element(all(a));
    int y = *max_element(all(b)) - *min_element(all(b));
    int ans = (max(x, y) + 1) / 2;
    cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}
