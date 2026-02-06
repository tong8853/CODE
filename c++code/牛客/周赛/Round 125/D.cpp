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
const ll INF = 1e9, p = 998244353;       // 注意判断 INF 具体的可能值

inline void solve(){
    int n, m;cin >> n >> m;
    string a, b;cin >> a >> b;
    int i = 0;
    int j = 0;
    while(1){
        if(a[i] == b[j]) i++,j++;
        else{
            while(1){
                i++;
                if(a[i] == '1'){
                    i++, j++;
                    break;
                }
                if(i == n) break;
            }
        }
        if(i == n || j == m) break;
    }
    int cnt = 0;
    rep(k, i, n - 1){
        if(a[k] == '1') cnt++;
    }
    if(cnt % 2){
        cout << "NO" << endl;
        return;
    }
    cout << (j == m ? "YES" : "NO") << endl; 
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}