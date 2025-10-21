#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<double> a(n + 1);
    a[0] = 0, a[1] = 1, a[2] = 1;
    rep(i, 3, n){
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << fixed << setprecision(2) << a[n] << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
