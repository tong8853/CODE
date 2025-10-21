#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

void solve(){
    int x;cin >> x;
    int a = 0, b = a ^ x;
    cout << a << " " << b << endl;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
