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


int b[] = {0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535};

inline void solve(){
    vi a(65536);
    int n;cin >> n;
    per(i, n, 1){
        cout << b[i] << " ";
        a[b[i]] = 1;
    } 
    rep(i, 0, b[n]){
        if(!a[i]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}