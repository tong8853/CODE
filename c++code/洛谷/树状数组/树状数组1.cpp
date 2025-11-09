#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, q;
int a[500005];
ll b[500005];

inline int lowbit(int x){
    return x & -x;
}

void update(int i, int x){//a[i] += x, 同步更新所有变更的b[i]
    while(i <= n){
        b[i] += x;
        i += lowbit(i);
    }
}

ll qzh(int i){
    ll ans = 0;
    while(i > 0){
        ans += b[i];
        i -= lowbit(i);
    }
    return ans;
}

void solve(){
    cin >> n >> q;
    rep(i, 1, n)cin >> a[i];
    rep(i, 1, n) update(i, a[i]);
    while(q--){
        int op;cin >> op;
        if(op == 1){
            int x, k;cin >> x >> k;
            update(x, k);
        }else{
            int x, y;cin >> x >> y;
            cout << qzh(y) - qzh(x - 1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}