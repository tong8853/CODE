#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

int gcd(int a, int b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve(){
    int n, ans;
    cin >> n;
    vector<int> a(n + 1), b(n);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n - 1) b[i] = a[i] ^ a[i + 1];
    ans = gcd(b[1], b[2]);
    rep(i, 3, n - 1){
        ans = gcd(ans, b[i]);
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
