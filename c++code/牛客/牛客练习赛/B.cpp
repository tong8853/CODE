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

//不行，时间复杂度太大了
int a[1000001];
inline void solve(){
    int n;cin >> n;
    vi b(n + 1);
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n - 1){
        rep(j, i + 1, n){
            if(b[i] > b[j] && a[b[i] * b[j]]){
                swap(b[i], b[j]);
            }
        }
    }
    bool ok = true;
    rep(i, 1, n - 1){
        if(b[i] > b[i + 1]){
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    rep(i, 1, 1000){
        a[i * i] = 1;
    }
    int T = 1;//cin >> T;
    while(T--)solve();
}