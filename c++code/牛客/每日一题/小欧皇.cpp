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

const int N = 1e5 + 10;
int f[N], siz[N], b[N];
vi edge[N];
int findfa(int x){
    if(f[x] != x) f[x] = findfa(f[x]);
    return f[x];
} 
void merge(int x, int y){
    int fx = findfa(x), fy = findfa(y);
    if(fx != fy){
        f[fx] = fy;
        siz[fy] += siz[fx];
    }
}
void solve(){
    int n, m;cin >> n >> m;
    rep(i, 1, n) f[i] = i, siz[i] = 1;
    rep(i, 0, m - 1){
        int x, y;cin>> x >> y;
        if(b[x] && b[y]) merge(x, y);
        edge[x].push_back(y);
        edge[x].push_back(x);
    }

    ll sum = 0;
    rep(i, 1, n){
        if(b[i] && findfa(i) == i) sum += siz[i] + (siz[i] - 1) / 2;
    }
    ll ans = 0;
    int pos = 0;
    rep(i, 1, n){
        if(!b[i]){
            set<int> st;
            for(auto j : edge[i]) if(b[j]) st.insert(findfa(j));
            ll tmp = sum, num = 1;
            for(auto x : st){
                tmp -= siz[x] + (siz[x] - 1) / 2;
                num += siz[x];
            }
            tmp += num * (num - 1) / 2;
            if(ans < tmp) ans = tmp, pos = i;
        }
    }
    cout << pos << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}