#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;
//3 3 4 1
//2 7 1 8
//min = 2 + 3 + 1 + 1 = 7

//3 3 4 1
//2 7 3 8
//min = 2 + 3 + 3 + 1 = 9

//7 3 4 1
//2 7 3 8
//min = 9
void solve(){
    int n, q;cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];

    ll min_sum = 0;
    rep(i, 1, n){
        min_sum += min(a[i], b[i]);
    }
    while(q--){
        char c;cin >> c;
        int x, y;cin >> x >> y;
        int min_1 = min(a[x], b[x]);
        if(c == 'A') a[x] = y;
        else b[x] = y;
        int min_2 = min(a[x], b[x]);
        min_sum += (min_2 - min_1);
        cout << min_sum << endl;
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
}
