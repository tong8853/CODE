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

inline void solve(){
    int n;cin >> n;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];

    unordered_set<int> s; // 存储已出现的数字
    int cnt = 0;          // 当前最少顺子数

    rep(i, 1, n) {
        int x = a[i];
        s.insert(x);

        // 新加入一个数，先认为它开启一个新段
        cnt++;

        // 如果 x-1 存在，它可以和新段连接，相当于减少一个段
        if (s.count(x - 1)) cnt--;

        // 如果 x+1 存在，它也可以和新段连接，相当于减少一个段
        if (s.count(x + 1)) cnt--;

        cout << cnt << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}