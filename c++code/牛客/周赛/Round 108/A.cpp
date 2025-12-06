#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    vector<int> a(5);
    rep(i, 1, 4){
        cin >> a[i];
    }
    if(a[1] < 425 && (a[2] < 60 || a[3] < 60 || a[4] < 60)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
}
