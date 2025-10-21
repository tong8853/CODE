#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int find(int x){
    int bit = 0;
    while(x){
        x = x >> 1;
        bit++;
    }
    return bit;
}
void solve(){
    int x, y, z;cin >> x >> y >> z;
    int bitx = find(x);
    int bity = find(y);
    int bitz = find(z);
    int max_bit = max(bitx, max(bity, bitz));
    bool ok = true;
    rep(i, 0, max_bit - 1){
        int bx = (x >> i) & 1;
        int by = (y >> i) & 1;
        int bz = (z >> i) & 1;

        if((!(bx ^ by)) != bz){
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}