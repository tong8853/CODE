#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    int n, m;cin >> n >> m;
    int cnt = 0;
    bool ok = true;
    rep(i, 1, n){
        int a, b;cin >> a >> b;
        if(ok){
            if((a + b) % 2 == 1){
                cnt++;
                ok = !ok;
            }
        }else{
            if((a + b) % 2 == 0){
                cnt++;
                ok = !ok;
            }
        }
    }
    cout << m - cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
