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

int n, a[1000010];
int pre(int x){//x 的“最低位 0”的位置
    rep(i, 0, n){
        if(!(x & (1 << i))) return i;
    }
    return -1;
}

inline void solve(){
    cin >> n;
    int k = (1 << n);
    rep(i, 0, k - 1) a[i] = i;
    sort(a, a + k, [&](int x, int y){
        if(pre(x) != pre(y)) return pre(x) > pre(y);
        return x < y;
    });
    rep(i, 0, k - 1) cout << a[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}