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

vector<int> in, out;
vector<vector<int>> res;
stack<int> st;
int n;

//现在轮到第 index 辆火车考虑，是进站，还是先让站里的火车出站？
void dfs(int index) {
    if (index == n && st.empty()) {
        res.push_back(out);
        return;
    }

    //两种走向：1让车站里面的车先出来 2让index这辆车先进去

    if (index < n) {//直接让index这辆火车进去
        st.push(in[index]);
        dfs(index + 1);
        st.pop(); //回溯
    }

    if (!st.empty()) {//先让里面的出来再考虑index这个车的事
        out.push_back(st.top());
        st.pop();
        dfs(index);
        st.push(out.back()); //回溯
        out.pop_back(); //回溯
    }
}


inline void solve(){
    cin >> n;
    //清空
    in.clear();
    out.clear();
    res.clear();
    while (!st.empty()) st.pop();

    in.resize(n);
    rep(i, 0, n - 1) {
        cin >> in[i];
    }

    dfs(0);

    sort(all(res));

    for (auto &v : res) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}