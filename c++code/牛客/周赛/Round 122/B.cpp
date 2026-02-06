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

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

inline void solve(){
    int n, m;cin >> n >> m;
    if(n > m) swap(n, m);
    int x = (m + 3) / 4;
    int y = (m + 1) / 4;
    ll ans = 0;
    int cnt = (n + 1) / 2;
    if(cnt % 2 == 0){
        ans += (x * 1LL * (cnt / 2));
        ans += (y * 1LL * (cnt / 2));
    }else{
        ans += (x * 1LL * (cnt / 2) + x);
        ans += (y * 1LL * (cnt / 2));
    }
    if(cnt < 2) cout << 1 << endl;
    else cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}