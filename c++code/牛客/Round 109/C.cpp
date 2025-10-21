#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(){
    ll x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
    ll dx = x2 - x1, dy = y2 - y1;
    ll x, y;
    if(dx != 0){
        if(dx % 2 == 0){
            x = x1, y = y1 + 1;
        }else{
            x = x1, y = y1 + 2;
        }
    }else{
        if(dy % 2 == 0){
            x = x1 + 1, y = y1;
        }else{
            x = x1 + 2, y = y1;
        }
    }
    cout << x << " " << y << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
