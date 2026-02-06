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

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    vi a(26);
    for(auto c : s) a[c - 'a']++;

    ll ans = 0;
    rep(i, 0, 25){
        if(a[i] == 0) continue;
        rep(j, i + 1, 25){
            if(a[j] == 0) continue;
            rep(k, j + 1, 25){
                if(a[k] == 0) continue;

                ans = (ans + ((a[i] * a[j] % p)) * a[k] % p) % p;
            }
        }
    }
    ans = ans * 6 % p;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}