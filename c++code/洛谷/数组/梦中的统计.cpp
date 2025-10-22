#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int ans[10];
void solve(){
    int a, b;cin >> a >> b;
    rep(i, a, b){
        string s = to_string(i);
        rep(j, 0, s.size() - 1){
            ans[(s[j] - '0')]++;
        }
    }
    for(auto x : ans) cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}