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
    int n, m;cin >> n >> m;
    vi a(n + 1);
    rep(i, 1, n)cin >> a[i];
    ll ans = INT_MAX;
    rep(i, 1, n - m + 1){
        int sum = 0;
        rep(j, i, i + m - 1){
            sum += a[j];
        }
        if(sum < ans) ans = sum;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}