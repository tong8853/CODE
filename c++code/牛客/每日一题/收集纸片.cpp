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

int a[25], b[25];
void solve(){
    int x, y;cin >> x >> y;
    cin >> a[0] >> b[0];
    int n;cin >> n;
    rep(i, 1, n){
        cin >> a[i] >> b[i];
    }
    sort(a, a + 1 + n);
    sort(b, b + 1 + n);
    cout << "The shortest path has length ";
    cout << 2 * (a[n] - a[0] + b[n] - b[0]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}