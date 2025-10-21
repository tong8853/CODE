#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    int n;cin >> n;
    vector<string> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
    }
    int x;cin >> x;
    string s;cin >> s;
    if(a[x] == s) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
}
