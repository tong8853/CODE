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
    int l, n;cin >> l >> n;
    int cnt = l + 1;
    vi a(n), b(n);
    rep(i, 0, n - 1){
        cin >> a[i];
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    cnt -= (b[0] - a[0] + 1);
    rep(i, 1, n - 1){
        if(a[i] > b[i - 1]) cnt -= (b[i] - a[i] + 1);
        else cnt -= (b[i] - b[i - 1]);
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}