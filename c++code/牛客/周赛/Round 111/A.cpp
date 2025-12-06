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
    vi a(3);
    rep(i, 0, 2) cin >> a[i];
    bool ok = true;
    rep(i, 1, 2){
        if(a[i] != (a[i - 1] + 1)){
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}