#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n, m;cin >> n >> m;
    vi a(n), b(m);
    rep(i, 0, n - 1)cin >> a[i];
    rep(i, 0, m - 1)cin >> b[i];
    auto cmp = [](int x, int y){
        return x > y;
    };
    sort(all(a), cmp);
    sort(all(b));
    int index = -1;
    rep(i, 0, m - 1){
        index += b[i];
        if(index > n - 1) break;
        a[index] = 0;
    }
    ll sum = 0;
    rep(i, 0, n - 1){
        sum += a[i];
    }
    cout << sum << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
