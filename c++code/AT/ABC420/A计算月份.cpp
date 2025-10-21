#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    int x, y; cin >> x >> y;
	int sum = x + y;
    cout << (( sum % 12 == 0) ? 12 : (sum % 12)) << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
}
