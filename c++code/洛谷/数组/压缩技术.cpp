#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MAXN = 205;
int pos[MAXN][MAXN];
void solve(){
    int n;cin >> n;
    vi a;
    int x;
    string s;
    bool t = false;
    int sum = 0;
    while(cin >> x){
        if(!t)rep(i, 1, x) s.push_back('0');
        else rep(i, 1, x) s.push_back('1');
        t = !t;
        sum += x;
        if(sum == n * n) break;
    }
    rep(i, 0, n * n - 1){
        cout << s[i];
        if(i % n == n  -1) cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}