#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

void solve(){
    int k;cin >> k;
    int n = 1;
    double sum = 0;
    while(1){
        sum += 1.0 / n;
        if(sum > k){
            break;
        }
        n++;
    }
    cout << n << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;//cin >> T;
	while(T--) solve();
}
