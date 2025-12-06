#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int p = 1000000007;

void solve(){
    int n;cin >> n;
    ll x, y;cin >> x >> y;
    rep(i, 1, n - 1){
        ll a, b;cin >> a >> b;
        ll tempx = x;
        ll tempy = y;
        x = (a * tempx % p - b * tempy % p) % p;
        y = (tempx * b % p + a * tempy % p) % p;
    }
    cout << (x + p) % p << " " << (y + p) % p <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}