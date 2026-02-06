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
    int n;cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll sum = 0;
    rep(i, 0, n - 1) sum += a[i];
    int maxx = *max_element(all(a));
    int minx = *min_element(all(a));
    ll ans = 1LL * maxx + 1LL * n * minx;
    cout << (ans < sum ? ans : sum) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}