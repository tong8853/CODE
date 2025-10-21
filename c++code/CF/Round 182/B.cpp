#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

map<int, int> mp;
void solve(){
    int n;cin >> n;
    rep(i, 0, n) mp[i] = 0;
    vi a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        mp[a[i]]++;
    }
    if(mp[0] == 1){
        int pos = n + 1, num = n + 1;
        rep(i, 1, n){
            if(a[i] == 0) pos = i;
        }
        rep(i, 1, n){
            if(mp[i] == 0) num = i;
        }
        a[pos] = num;
    }
    int cnt = 0;
    rep(i, 1, n){
        if(a[i] == i) cnt++;
        else{
            break;
        }
    }
    for(int i = n; i >= 1; i--){
        if(cnt == n) break;
        if(a[i] == i) cnt++;
        else{
            break;
        }
    }
    cout << n - cnt << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
