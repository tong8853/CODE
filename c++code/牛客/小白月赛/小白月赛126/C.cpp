#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(int l, int r, T &a){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

inline void solve() {
    ll n, p, k;
    if (!(cin >> n >> p >> k)) return;

    unordered_map<string, ll> cnt;
    ll sum = 0;

    // 读取所有歌曲的游玩记录
    rep(i, 1, n){
        string s;ll a;
        cin >> s >> a;
        cnt[s] = a;
        sum += a;
    }

    ll minx = 2e18;
    rep(i, 1, k){
        string t;cin >> t;
        if(cnt.count(t)){
            minx = min(minx, cnt[t]);
        }
    }

    if(p < k){
        cout << -1 << endl;
        return;
    }

    ll L = (sum + p - 1) / p;
    ll R = minx;

    if(L > R){
        cout << -1 << endl;
    }else{
        cout << L << " " << R << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}