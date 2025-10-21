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
    vi a(8), ans(8);
    int n;cin >> n;
    rep(i, 1, 7) cin >> a[i];
    while(n--){
        int x;
        int cnt = 8;
        rep(i, 1, 7){
            cin >> x;
            rep(j, 1, 7){
                if(x == a[j]) cnt--;
            }
        }
        if(cnt < 8) ans[cnt]++;
    }
    rep(i, 1, 7) cout << ans[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}