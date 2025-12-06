#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int n;cin >> n;
    vi a(n + 1);rep(i, 1, n)cin >> a[i];
    ll ans = 0;
    for(int j = 3; j > 0; j--){
        rep(i, 1, n){
            if(a[i] == j){
                ans += j;
                if(i == 1){
                    a[i] = 0;
                    a[i + 1] = 0;
                }else if(i == n){
                    a[i] = 0;
                    a[i - 1] = 0;
                }else{
                    rep(k, i - 1, i + 1){
                        a[k] = 0;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}