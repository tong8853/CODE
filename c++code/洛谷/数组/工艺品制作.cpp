#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int a[23][23][23] = {0};
void solve(){
    int x, y, z;cin >> x >> y >> z;
    int ans = x * y * z;
    int q;cin >> q;
    while(q--){
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        rep(i, x1, x2){
            rep(j, y1, y2){
                rep(k, z1, z2){
                    if(a[i][j][k] == 0){
                        a[i][j][k] = 1;
                        ans--;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}