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
     ll sum;
     int n;cin >> n;
     vi a, b;
     rep(i, 0, n - 1){
        int x;cin >> x;
        a.push_back(x);
     }
     sort(all(a));
     int k = 0, mx = n - 1;
     ll cnt1 = 0;
     while(k < a[mx]){
        cnt1 += (a[mx] - k);
        mx--;
        k++;
     }
     cout << cnt1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}