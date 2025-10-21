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
    priority_queue<int, vector<int>, greater<int>> a;
    rep(i, 1, n){
        int x;cin >> x;
        a.push(x);
    }
    ll ans = 0;
    while(a.size() != 1){
        int x = a.top(); a.pop();
        int y = a.top(); a.pop();
        ans += x + y;
        a.push(x + y);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}