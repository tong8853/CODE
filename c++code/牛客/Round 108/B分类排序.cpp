#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    int n;cin >> n;
    vector<int> a, b;
    rep(i, 1, n){
        int x;cin >> x;
        if(x % 2 == 0){
            a.push_back(x);
        }else{
            b.push_back(x);
        }
    }
    sort(all(a));sort(all(b));
    for(auto x : a) cout << x << " ";
    for(auto x : b) cout << x << " ";
    cout << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--) solve();
}
