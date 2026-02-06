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
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

int n;
int cnt[30];//记录字母数量

inline void solve(){
    cin >> n;
    string s;cin >> s;
    vi a(n);
    read(a, 0, n - 1);
    vi tmp;
    vector<vi> ans;
    rep(i, 0, n - 1){
        int c = s[i];

        if(cnt[c - 'a'] == 0){
            ans.push_back(tmp);
            tmp.clear();
            tmp.push_back(a[i]);
            cnt[c - 'a']++;
        }else{

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}