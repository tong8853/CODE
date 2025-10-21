#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    int n;cin >> n;
    rep(i, 0, n - 1){
        rep(j, 1, n){
            cout << setfill('0') << setw(2) << n * i + j;
            if(j == n) cout << endl;
        }
    }
    cout << endl;
    
    int num = 1;
    rep(i, 1, n){
        rep(j, 1, 2*(n - i)) cout << " "; 
        rep(j, 1, i){
            cout << setfill('0') << setw(2) << num;
            num++;
        }
        cout << endl;
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
