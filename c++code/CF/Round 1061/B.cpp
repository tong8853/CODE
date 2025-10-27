#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

struct node{
    char p;
    int m;
};
void solve(){
    int n, q;cin >> n >> q;
    vector<char> a(n + 1);rep(i, 1, n)cin >> a[i];
    vector<node> b;
    int mx = 1;
    char init = a[1];
    rep(i, 2, n){
        if(a[i] == init) mx++;
        else{
            b.push_back(node{init, mx});
            init = a[i];
            mx = 1;
        }
    }
    b.push_back(node{init, mx});
    while(q--){
        int ans = 0;
        int x;cin >> x;
        int i = 0;
        int len = b.size();
        while(x){
            if(len == 1 && b[i].p == 'A'){
                ans = x;
                break;
            }
            if(b[i].p == 'A'){
                int take = min(x, b[i].m);
                ans += take;
                x -= take;
            }else{
                rep(j, 1, b[i].m){
                    x /= 2;
                    ans++;
                    if(x == 0) break;
                }
            }
            i = (i + 1) % len;
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}