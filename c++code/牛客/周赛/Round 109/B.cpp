#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<pair<int, int>> a(n + 1);
    rep(i, 1, n){
        cin >> a[i].first >> a[i].second;
    }
    int cnt = 0;
    rep(i, 1, n - 1){
        rep(j, i + 1, n){
            if((abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second)) == 1){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
