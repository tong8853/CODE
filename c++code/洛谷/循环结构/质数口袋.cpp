#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

bool isZhi(int x){
    if(x == 1) return false;
    if(x == 2) return true;
    rep(i, 2, (int)sqrt(x)){
        if(x % i == 0) return false;
    }
    return true;
}

void solve(){
    int m;cin >> m;
    int sum = 0, cnt = 0;
    rep(i, 1, m){
        if(isZhi(i) && sum + i <= m){
            cout << i << endl;
            sum += i;
            cnt++;
        }
        if(sum + i > m) break;
    }
    cout << cnt << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;//cin >> T;
	while(T--) solve();
}
