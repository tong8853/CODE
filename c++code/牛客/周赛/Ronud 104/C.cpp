#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

unordered_map<int, int> mp;

void solve(){
    int n;cin >> n;
   rep(i, 1, 2 * n){
        int x;cin >> x;
        mp[x]++;
   }
   int cnt = 0;
   rep(i, 1, n){
        if(mp[i] >= 2) cnt += 2;
        if(mp[i] == 1) cnt++;
   }
   cout << cnt << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}
