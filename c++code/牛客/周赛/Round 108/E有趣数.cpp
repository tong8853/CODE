#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    int n;cin >> n;
    int sum = 0;
    int cnt = 0;
    rep(i, 1, n){
        int x;cin >> x;
        if(x == 1) cnt++;
        else sum += x;
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--) solve();
}
