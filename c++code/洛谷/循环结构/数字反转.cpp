#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    ll a;cin >> a;
    bool ok = true;
    if(a < 0) ok = false;
    string s = to_string(a);
    reverse(all(s));
    a = stoll(s);
    cout << (ok ? a : -a) << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;//cin >> T;
	while(T--) solve();
}
