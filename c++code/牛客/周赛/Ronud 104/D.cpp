#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(){
    int n, m;cin >> n >> m;
    vector< vector<int> > a(n + 1, vector<int>(m + 1));
    int cnt = 0;
    rep(i, 1, n) rep(j, 1, m){
        cin >> a[i][j];
        if(a[i][j] == min(i, j)) cnt++;
    }
    //先遍历看有没有加2的机会
    rep(i, 1, n) rep(j, 1, m){

    }
    //再遍历看有没有加1的机会


    cout << cnt << endl;

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}
