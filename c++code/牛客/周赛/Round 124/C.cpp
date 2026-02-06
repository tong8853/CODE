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
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

inline void solve(){
    int n, m;cin >> n >> m;
    vi a(n);
    read(a, 0, n - 1);
    if(n + 1 < m){
        cout << "NO" << endl;
        return;
    }
    sort(all(a));
    int pre = 0, cur = 1;
    rep(i, 1, n - 1){
        if(a[i] - a[i - 1] == 1) cur++;
        else if(a[i] - a[i - 1] == 2){
            pre = cur;
            cur = 1;
        }else{
            pre = 0;
            cur = 1;
        }
        if(cur + 1 == m){
            cout << "YES" << endl;
            return;
        }
        if(cur + pre + 1 == m){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}