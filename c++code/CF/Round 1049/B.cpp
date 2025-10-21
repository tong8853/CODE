#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

//设y是n位数 x#y = x * 10^n + y = x * (10^n - 1) + (x + y)
//只需关注x * (10^n - 1)即可， 容易知道 3x 是该式子的因子，则构造x + y = 3x，即y = 2x即可
void solve(){
    int x;cin >> x;
    cout << 2 * x << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--) solve();
}
