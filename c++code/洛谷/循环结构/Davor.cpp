#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(){
    int n;cin >> n;
    int a = n / 52 / 7;
    int x, k;
    for(int i = 100; i > 0; i--){
        if((a - i) % 3 == 0 && (a - i) / 3 > 0){
            x = i;
            k = (a - i) / 3;
            break;
        }
    }
    cout << x << endl << k << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
