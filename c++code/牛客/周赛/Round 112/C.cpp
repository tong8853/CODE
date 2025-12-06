#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

bool cmp(int x, int y){
    return x > y;
}

void solve(){
    string s;cin >> s;
    vector<int> a;
    int cnt = 0;
    rep(i, 0, s.size() - 1){
        if(s[i] == '0') cnt++;
        else{
            a.push_back(cnt);
            cnt = 0;
        }
    }
    bool ok = true;
    int n = a.size();
    rep(i, 0, n / 2  - 1){
        if(a[i] != a[n - i - 1]){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << 1 << endl;
        return;
    }else{
        int ans = 0;
        sort(all(a), cmp);
        vector<bool> ok(n);
        for(int i = 0; i <= n - 1 && ok[i] == false; i++){
            for(int j = i + 1; j <= n - 1 && ok[j] == false; j++){
                if(a[i] - a[j] >= 0){
                    ok[j] = true;
                    a[i] = a[i] - a[j];
                    ans++;
                }
                if(a[i] == 0) ok[i] = true;
            }
        }
        rep(i, 0, n - 1) if(!ok[i]) ans++;
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}