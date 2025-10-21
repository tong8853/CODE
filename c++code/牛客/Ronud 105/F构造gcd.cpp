#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

int gcd(int a, int b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve(){
   int n, m, x;cin >> n >> m >> x;
   
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while (T--) solve();
}


