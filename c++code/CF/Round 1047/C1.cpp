#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;
//1. a+b需要最大
//2. a+b是个偶数

//除以一个数字对和的负面影响远小于乘以一个数字对和的正面影响
//若无条件二，最大值显然是(a, b) = (ab, 1)时
//1.如果a,b都是偶数我们可以将（a, b)变为（ab / 2, 2)这要求ab至少包含因子4
//2.得到（ab, 1)，要求ab不包含因子2，则a,b都是奇数
void solve(){
    ll a, b;cin >> a >> b;
	if(a * b % 2 != 0) cout << a * b + 1 << endl;
    else if(b % 2 == 0 && a * b % 4 == 0) cout << a * b / 2 + 2 << endl;
	else cout << -1 << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--) solve();
}
