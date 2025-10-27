#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    string s, st;
    int cnt = 0;
    while(cin >> s){
        cnt++;
        st += s;
    }
    cout << cnt << " ";
    int p = 0;
    int ans = 0;
    rep(i, 0, st.size() - 1){
        if(st[i] - '0' == p){
            ans++;
        }
        if(st[i] - '0' != p){
            cout << ans << " ";
            ans = 1;
            p = 1 - p;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}