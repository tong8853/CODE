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
inline void read(int l, int r, T &a){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

inline void solve(){
    int n, q;cin >> n >> q;

    // 统计每个难度值 v 覆盖了多少首歌
    // 注意：如果一首歌两个版本难度相同，只算一次
    vector<int> cnt(n + 5, 0);
    // 统计特定组合的歌曲数量
    vector<int> pair1(n + 5, 0); // 难度为 {v, v+1} 的歌曲数
    vector<int> pair2(n + 5, 0); // 难度为 {v, v+2} 的歌曲数

    rep(i, 0, n - 1){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        
        cnt[a]++;
        if(a != b){
            cnt[b]++;
            // 只记录间距在 2 以内的组合，因为询问区间跨度只有 3
            if(b - a == 1) pair1[a]++;
            else if(b - a == 2) pair2[a]++;
        }
    }

    rep(i, 0, q-1){
        int x;cin >> x;
        
        // 目标区间 [L, M, R] = [x-1, x, x+1]
        int L = x - 1, M = x, R = x + 1;
        
        long long gs = 0;
        
        // 累加单个难度的覆盖数
        if (L >= 1) gs += cnt[L];
        if (M >= 1 && M <= n) gs += cnt[M];
        if (R <= n) gs += cnt[R];

        // 减去重复统计的歌曲（即两版难度都在 [x-1, x+1] 内的歌）
        if (L >= 1 && M <= n) gs -= pair1[L];   // {x-1, x}
        if (M >= 1 && R <= n) gs -= pair1[M];   // {x, x+1}
        if (L >= 1 && R <= n) gs -= pair2[L];   // {x-1, x+1}

        // 最小不舒适度 = 总歌曲数 - 舒适歌曲数
        cout << n - gs << (i == q - 1 ? "" : " ");
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}