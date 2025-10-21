#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int a[105], b[105];
void solve(){
    int n;cin >> n;
    a[0] = 1, b[0] = 1;
    rep(i, 2, n){
        //a保存当前i!
        rep(j, 0, 100) a[j] *= i;
        rep(j, 0, 100){
            if(a[j] >= 10){
                a[j + 1] += a[j] / 10;
                a[j] %= 10;
            }
        }

        //b保存当前的Si
        rep(j, 0, 100) b[j] += a[j];
        rep(j, 0, 100){
            if(b[j] >= 10){
                b[j + 1] += b[j] / 10;
                b[j] %= 10;
            }
        }
    }
    int pos;
    for(pos = 100; pos >= 0 && b[pos] == 0; pos--);
    for(int i = pos; i >= 0; i--) cout << b[i];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}