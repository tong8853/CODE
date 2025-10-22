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
    vi a(n);
    set<int> st;
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 2){
        rep(j, i + 1, n - 1){
            st.insert(a[i] + a[j]);
        }
    }
    ll ans = 0;
    rep(i, 0, n - 1){
        if(st.find(a[i]) != st.end()){
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}