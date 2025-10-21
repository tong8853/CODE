#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(){
    vector<ll> a(11);
    cin >> a[1] >> a[2];
    rep(i, 3, 10){
        string s = to_string(a[i - 2] + a[i - 1]);
        reverse(all(s));
        a[i] = stoll(s);
    }
    cout << a[10] << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
}
