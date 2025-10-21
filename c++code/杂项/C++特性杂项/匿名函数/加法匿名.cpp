#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(){
    auto f = [](int a, int b) -> int{//返回值类型可以省略
        return a + b;
    };
    cout << f(1, 2) << endl;

    auto g = [](int a, int b){
        return a + b;
    };
    cout << g(1, 2) << endl;

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
