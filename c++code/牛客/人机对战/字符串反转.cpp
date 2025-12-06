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
    string s;cin >> s;
    int n = s.size();
    vi a(n + 1);
    rep(i, 0, n - 1){
        if(s[i] >= 'A' && s[i] < 'a') a[i + 1] = 1;
    }
    PII pre = {0, 0}, ls = {0, 0};//记录前缀数组有多少个大写字母，有多少个小写字母
    //预处理出分割点为1的情况
    int k = 1;
    if(a[k] == 1) pre.ff++;
    else pre.ss++;
    rep(i, 2, n){
        if(a[i] == 1) ls.ff++;
        else ls.ss++;
    }
    int cnt = pre.ss + ls.ff;
    int ans = min(INT_MAX, cnt);
    k = 2;
    //滑动窗口
    while(k < n){//1 ~ n - 1
        //移入a[k]进前缀，从后缀移除a[k]
        if(a[k] == 0) cnt++;
        if(a[k] == 1) cnt--;
        ans = min(ans, cnt); 
        k++;
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}