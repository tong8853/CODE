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
    int n;cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    sort(all(a));
    ll ans = 0;
    for(int i = 1; i < n; i += 2){
        int cha = a[i] - a[i - 1];
        if(cha > ans) ans = cha;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}