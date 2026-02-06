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
typedef vector<vector<int>> vii;
typedef vector<ll> vll;

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

int f(int n){
    int i = 2;
    while(i * i <= n){
        while(n % (i * i) == 0){
            n /= (i * i);
        }
        i++;
    }
    return n;
}
inline void solve(){
    int n;cin >> n;
    vi a(n + 1), b(n + 1);
    map<int, vi> pos;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n){
        b[i] = f(a[i]);
        pos[b[i]].push_back(i);
    }
    for(auto &x : pos){
        vi pos = x.ss;
        vi wait;
        for(auto &z : pos){
            wait.push_back(a[z]);
        }
        sort(all(wait));
        rep(i, 0, wait.size() - 1){
            a[pos[i]] = wait[i];
        }
    }
    bool ok = true;
    rep(i, 1, n - 1){
        if(a[i] > a[i + 1]){
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}