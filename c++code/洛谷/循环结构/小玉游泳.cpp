#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    double m;cin >> m;
    double sum = 0;
    int cnt = 0;
    double a = 2;
    while(sum < m){
        sum += a;
        cnt++;
        a = a * 0.98;
    }
    cout << cnt << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;//cin >> T;
	while(T--) solve();
}
