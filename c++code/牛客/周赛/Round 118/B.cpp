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
    vector<PII> a;
    rep(i, 1, n){
        int x, y;cin >> x >> y;
        a.push_back({x, y});
    }
    int L = -1e8;
    PII P1, P2;
    rep(i, 0, n - 1){
        rep(j, i + 1, n - 1){
            int dx = a[i].ff - a[j].ff;
            int dy = a[i].ss - a[j].ss;
            int L1 = dx * dx + dy * dy;
            if(L1 > L){
                L = L1;
                P1 = {a[i].ff, a[i].ss};
                P2 = {a[j].ff, a[j].ss};
            }
        }
    }
    cout << P1.ff << " " << P1.ss << " " << P2.ff << " " << P2.ss;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}