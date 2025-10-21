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
    string s;cin >> s;
    vi a(n + 1);
    rep(i, 1, n){
        a[i] = s[i - 1] - '0';
    }
    ll ans = 0;
    for(int i = 3; i <= n; i += 3){
        map<int, int> mp;
        rep(j, 1, i) mp[a[j]]++;
        if(mp[1] == mp[2] && mp[2] == mp[3]) ans++;
        rep(j, 2, n - i + 1){
            mp[a[j - 1]]--;
            mp[a[j + i -1]]++;
            if(mp[1] == mp[2] && mp[2] == mp[3]) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}