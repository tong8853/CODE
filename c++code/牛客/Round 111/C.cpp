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
    int n;
    ll k;
    int x;
    cin >> n >> k >> x;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    deque<int> b;
    rep(i, 1, x){
        b.push_back(a[i]);
    }
    k %= x;
    while(k--){
        b.push_front(b.back());
        b.pop_back();
    }
    for(auto x : b) cout << x << " ";
    rep(i, x + 1, n) cout << a[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}