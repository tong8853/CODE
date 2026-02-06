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

ll n, k, m, x, y;
inline void solve(){
    cin >> n >> k;
    string s;cin >> s;
    vll ans(n + 1);
    ll cur = 0, cnt = 0;
    rep(i, 0, s.length() - 1){
        if(s[i] == '0') cnt++;
        if(s[i] == '1') cnt = 0;
        if(cnt == k){
            ans[cur++] = i;
            cnt = 0;
        }
    }    
    while(cur <= n){
        ans[cur++] = n;
    }
    for(auto x : ans) cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}