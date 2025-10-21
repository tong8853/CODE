#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

void solve(){
    int n, k; cin >> n >> k;
    if(n - k == 1){
        cout << -1 << endl;
        return;
    }
    rep(i, 1, k) cout << i << " ";
    if(n != k){
        rep(i, k + 1, n){
            if(i == k + 1) cout << n << " ";
            else cout << i - 1 << " ";
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}
