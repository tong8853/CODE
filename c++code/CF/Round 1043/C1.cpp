#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

//最少交易次数的情况下的硬币数
//要买n个西瓜，一次交易3**x个西瓜要3^(x+1) + x * 3^(x - 1)个硬币
//1 <= n <= 10**9 (约为3 ** 20)
//n = a.k * (3**k) + a.k-1 * (3**(k - 1)) + .... + a.1 * (3**1) + a.0 * (3**0)
//易知0 <= a.i < 3
/**
 * @brief 三进制拆解
 * n西瓜数， ans购买西瓜所需的最少硬币数
 * x对应位数
 * px当前位数对应的位权，即3^x
 */

void solve(){
    int n;cin >> n;
    ll ans = 0;
	ll px = 1;//记录当前位权,初始化对应到x = 0,3^x = 1
	for(int x = 0; n > 0; x++){//x为交易层级,从0次方开始
		while(n % 3){//若不是3的倍数，单独处理多余的1或2；若是3的倍数则不处理ans，n
			n--;
			ans += (3 * px + x * (px / 3));
		}
		//切换至下一个层级
		n /= 3;
		px *= 3;
	}
    cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
