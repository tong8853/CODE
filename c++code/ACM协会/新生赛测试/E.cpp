#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int p = 17;
int a[17];
void solve(){
    int n;cin >> n;
    int ans = 0;
    a[1] = 1;
    rep(i, 2, 16){
        a[i] = a[i - 1] * i % p;
    }
    if(n >= 17){
        rep(i, 1, 16){
            ans += a[i];
        }
    }else{
        rep(i, 1, n){
            ans += a[i];
        }
    }
    cout << ans % p << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}