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
    string a, b;cin >> a >> b;
    bool ok1 = false, ok2 = false;
    if(a[a.size() - 1] == '+'){
        ok1 = true;
        a.pop_back();
    }
    if(b[b.size() - 1] == '+'){
        ok1 = true;
        b.pop_back();
    }
    int x = stoi(a);
    int y = stoi(b);
    if(x != y){
        cout << (x > y ? "Yes" : "No") << endl;
    }else{
        if(ok1 && !ok2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}