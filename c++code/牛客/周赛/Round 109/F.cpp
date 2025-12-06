#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n;cin >> n;
    set<pair<int, int>> s;
    vector<pair<int, int>> a(n);
    for(auto &[x, y] : a){
        cin >> x >> y;
        s.insert({x, y});
    }

    ll ans = 0;

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
