#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    int n, m, x, y;cin >> n >> m >> x >> y;
    int a, b;
    rep(i, 1, n) cin >> a;
    rep(i, 1, m) cin >> b;
    cout << n + m << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
