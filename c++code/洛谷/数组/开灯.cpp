#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MAXN = 2000005;
bool LED[MAXN];
void solve(){
    int n;cin >> n;
    rep(i, 1, n){
        double x;cin >> x;
        int m;cin >> m;
        rep(j, 1, m){
            LED[(int)(x * j)] = !(LED[(int)(x * j)]);
        }
    }
    rep(i, 1, MAXN){
        if(LED[i]){
            cout << i << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}