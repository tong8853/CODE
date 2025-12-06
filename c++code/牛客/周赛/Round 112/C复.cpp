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
    string s;cin >> s;
    int cnt0 = 0, cnt1 = 0;
    rep(i, 0, s.size() - 1){
        if(s[i] == '0') cnt0++;
        else cnt1++;
    }
    if(cnt0 == 0 || cnt1 == 0) cout << 1 << endl;
    else{
        bool ok = true;
        int n = s.size();
        rep(i, 0, n / 2  - 1){
            if(s[i] != s[n - i - 1]){
                ok = false;
                break;
            }
        }
        if(ok) cout << 1 << endl;
        else cout << 2 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}