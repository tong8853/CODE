#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

bool ok(int x, int y, int z) {
    rep(k, 0, 30) {
        int xk = (x >> k) & 1;
        int yk = (y >> k) & 1;
        int zk = (z >> k) & 1;
        bool v = false;
        
        rep(a, 0, 1) rep(b, 0, 1) rep(c, 0, 1) {
            if ((a & b) == xk && (b & c) == yk && (a & c) == zk) {
                v = true;
                goto end;
            }
        }
        end:
        if (!v) return false;
    }
    return true;
}

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << (ok(x, y, z) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--) solve();
}