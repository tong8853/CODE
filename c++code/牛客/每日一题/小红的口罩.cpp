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
    int n, k;cin >> n >> k;
    priority_queue<int, vi, greater<int>> pq;
    int x;
    rep(i, 1, n){
        cin >> x;
        pq.push(x);
    }
    int cnt = 0;
    do{
        int t = pq.top();
        pq.pop();
        k -= t;
        if(k >= 0) cnt++;
        pq.push(2 * t);
    }while(k > 0);
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}