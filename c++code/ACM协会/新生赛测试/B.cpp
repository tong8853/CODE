#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int v, a, b, x;cin >> v >> a >> b >> x;
    int ans = 0;
    int n = x / (a + b);
    int time = x % (a + b);
    if(time <= a) ans += time * v;
    else ans += a * v; 
    ans += n * (a * v); 
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}