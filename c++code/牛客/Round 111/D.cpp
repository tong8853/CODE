#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

map<int, int> mp;
void solve(){
    int n;cin >> n;
    int x;
    rep(i, 1, n){
        cin >> x;
        x %= 11;
        mp[x]++;
    }
    ll ans = 0;
    rep(i, 1, 5){
        ans += 2 * mp[i] * mp[11 - i]; 
    }
    ans += (mp[0] * (mp[0] - 1)); 
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}