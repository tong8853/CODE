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
    int n; cin >> n;
    vi a(n + 1), b(n + 1);
    int ans1 = 0, ans2 = 0;
    rep(i, 1, n) cin >> a[i]; 
    rep(i, 1, n) cin >> b[i];
    int min = 100, max = 0;
    rep(i, 1, n){
        if(a[i] < min){
            ans1 = i;
            min = a[i];
        } 
    }
    rep(i, 1, n){
        if(b[i] > max){
            ans2 = i;
            max = b[i];
        }
    }
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}