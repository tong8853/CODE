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

void solve(){
    int n;cin >> n;
    vector<PII> a(n);
    rep(i, 0, n - 1)cin >> a[i].ff >> a[i].ss;
    sort(all(a));
    int min_x = INT_MAX, max_x = -INT_MAX;
    bool ok = true;
    rep(i, 0, n - 1){
        if(a[i].ff > min_x || a[i].ss < max_x){
            cout << "No" << endl;
            ok = false;
            break;
        }
        min_x = min(min_x, a[i].ss);//则min_x为当前已遍历的最小右端点
        max_x = max(max_x, a[i].ss);//则max_x为当前已遍历的最大右端点
    }
    if(ok) cout << "Yes" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
    return 0;
}