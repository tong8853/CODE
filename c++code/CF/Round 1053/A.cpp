#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)

void solve(){
    int n, m;cin >> n >> m;
    vector<int> a(m);
    rep(i, 0, m - 1) cin >> a[i];
    if(m == 1) cout << n - a[0] + 1 << endl;
    else{
        //判断是否连续
        bool ok = true;
        rep(i, 0, m - 2){
            if(a[i + 1] != a[i] + 1){
                ok = false;
                break;
            }
        }
        if(ok) cout << n - a[m - 1] + 1 << endl;
        else cout << 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}