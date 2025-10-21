#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n;cin >> n;
    vi a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    rep(i, 1, n - 1){
        rep(j, i + 1, n){
            int s1 = a[i], s2 = a[j] - a[i], s3 = a[n] - a[j];
            if((s1 + s2 + s3) % 3 == 0){
                cout << i << " " << j << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
