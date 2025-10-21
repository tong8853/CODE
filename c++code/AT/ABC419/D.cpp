#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

int qzh[500005];
void solve(){
    int n, m;cin >> n >>m;
    string S, T;cin >> S >> T;
    while(m--){
        int L, R;cin >> L >> R;
        qzh[L]++;
        qzh[R + 1]--;
    }
    rep(i, 1, n){
        qzh[i] += qzh[i - 1];
        if(qzh[i] % 2 == 0) cout << S[i - 1];
        else cout << T[i - 1];
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}
