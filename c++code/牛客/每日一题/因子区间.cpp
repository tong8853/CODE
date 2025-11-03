#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int n, q;cin >> n >> q;
    vi f(100100);
    rep(i, 1, 100000){ //枚举每一个因子
        for(int j = i; j <= 100000; j += i){
            f[j] += 1;
        } 
    }
    vi a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        a[i] = f[a[i]];
    }
    //因为1e5内的数最多只会有128个因子，开个pos数组记录同一因子数的位置
    vector<vector<int>> pos(130);//pos[i]记录了因子数为i的位置
    rep(i, 1, n){
        pos[a[i]].push_back(i);
    }
    while(q--){
        int l, r;cin >> l >> r;
        ll ans = 0;
        rep(i, 1, 128){
            int cnt = 0;
            for(auto x : pos[i]){
                if(x >= l && x <= r) cnt++;
            }
            ans += 1LL * cnt * (cnt - 1) / 2;
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}