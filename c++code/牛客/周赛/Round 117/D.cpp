#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int n;cin >> n;
    map<int, int> mp;
    rep(i, 1, n  -1){
        int a, b;cin >> a >> b;
        mp[a]++, mp[b]++;
    }
    ll ans = 0;
    for(auto x : mp){
        if(x.ss > 2) ans += x.ss - 2; 
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}