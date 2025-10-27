#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int p = 998244353;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int cnt_0 = 0;
    rep(i, 0, n - 1){
        if(s[i] == '0') cnt_0++;
    }
    if(cnt_0 % 2) cout << 0 << endl;
    else cout << 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}