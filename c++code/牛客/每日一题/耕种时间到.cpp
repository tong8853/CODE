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
    vi a(n);rep(i, 0, n - 1)cin >> a[i];
    int x;cin >> x;
    ll max_cnt = 0;
    int max_x = -INT_MAX;//记录当前的最高等级
    map<int, ll> mp;//mp[i]表示等级为i的小麦种子数
    bool ok = false;
    rep(i, 0, n - 1){
        if(a[i] == x) ok = true; 
        mp[a[i]]++;//第一次收割前每个等级的种子的数量
        max_x = max(a[i], max_x);
    }
    if(ok) max_cnt = mp[x];
    while(max_x > x){
        max_x = (max_x + 2) / 3;//更新当前的最大等级
        map<int, ll> now;
        for(auto [x, cnt] : mp){
            int now_x = (x + 2) / 3;
            now[now_x] += 2 * cnt;
        }
        mp = move(now);
        max_cnt = max(max_cnt, 1LL * mp[x]);
    }
    cout << max_cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}