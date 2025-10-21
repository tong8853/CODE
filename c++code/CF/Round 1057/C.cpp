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
    map<int, int> mp;
    priority_queue<int, vector<int>> a;
    rep(i, 1, n){
        int x;cin >> x;
        mp[x]++;
    }
    bool ok = false;
    for(auto &pair : mp){
        if(pair.second > 1){
            ok = true;
        }else{
            a.push(pair.first);
        }
    }
    if(n == 3 && ok){
        vi b(3);
        for(auto &pair : mp){
            rep(i, 1, pair.second){
                b.pb(pair.first);
            }
        }
        if(b[0] + b[1] > b[2] && b[1] + b[2] > b[0] && b[0] + b[2] > b[1]){
            ll ans = 0;
            rep(i, 0, 2) ans += b[i];
            cout << ans << endl;
            return;
        }else{
            cout << 0 << endl;
            return;
        }
    }
    ll ans = 0;
    if(ok){
        for(auto &pair : mp){
            ans += (pair.second / 2) * pair.first;
            pair.second -= 2 * (pair.second / 2);
            if(pair.second) a.push(pair.first);
        }
        ans += a.top();
        a.pop();
        ans += a.top();
        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}