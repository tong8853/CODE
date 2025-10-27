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
    int n, q;cin >> n >> q;
    vll a(n + 1);rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) a[i] += a[i - 1];
    while(q--){
        int L, R, m, k;cin >> L >> R >> m >> k;
        ll sum = a[R] - a[L - 1];
        if(sum >= k - m) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}