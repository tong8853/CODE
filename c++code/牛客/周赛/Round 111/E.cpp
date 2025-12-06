#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(){
    int n;ll k;
    cin >> n >> k;
    if(n == 1 && k == 2){
        cout << 1 << endl;
        return;
    }
    k -= (3 * n - 1);
    vi a;
    vector<bool> vis(n + 1);
    for(int i = n - 2;i >= 1; i--){
        if(k >= i){
            k -= i;
            a.pb(i);
            vis[i] = 1;
        }
        if(k <= 0) break;
    }
    if(k != 0){
        cout << -1 << endl;
        return;
    }
    for(int i = a.size() - 1; i>= 0; i--) cout << a[i] << " ";
    cout << n - 1 << " ";
    rep(i, 1, n - 2){
        if(!vis[i]) cout << i << " ";
    }
    cout << n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}