#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(){
    int n;cin >> n;
    int maxm = 0, minm = 20;
    double sum = 0;
    rep(i, 1, n){
        int x;cin >> x;
        if(x > maxm) maxm = x;
        if(x < minm) minm = x;
        sum += x;
    }
    sum -= maxm;
    sum -= minm;
    cout << fixed << setprecision(2) << sum / (n - 2) << endl; 
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
