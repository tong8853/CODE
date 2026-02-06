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

const int N = 2e5+5, M = 2e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值


int fa[N];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

struct node{
    int u, v, c;
};

inline void solve(){
    int n;cin >> n;
    vector<node> ops(n);
    vi nums;
    
    rep(i, 0, n - 1){
        cin >> ops[i].u >> ops[i].v >> ops[i].c;
        nums.push_back(ops[i].u);
        nums.push_back(ops[i].v);
    }

    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());
    auto get = [&](int x){
        return lower_bound(all(nums), x) - nums.begin() + 1;
    };

    //初始化并查集
    int sz = nums.size();
    rep(i, 1, sz) fa[i] = i;

    //处理朋友关系
    rep(i, 0, n - 1){
        if(ops[i].c == 1){
            int root1 = find(get(ops[i].u));
            int root2 = find(get(ops[i].v));
            if(root1 != root2) fa[root1] = root2;
        }
    }

    //检查所有敌人关系
    bool ok = true;
    rep(i, 0, n - 1){
        if(ops[i].c == 0){
            if(find(get(ops[i].u)) == find(get(ops[i].v))){
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "YES" : "NO") << endl;

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}