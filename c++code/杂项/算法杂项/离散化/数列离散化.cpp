#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1), b(n + 1);
    rep(i, 0, n - 1){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(all(a));
    int cnt = unique(all(a)) - a.begin();
    rep(i, 0, n - 1){
        b[i] = lower_bound(a.begin(), a.begin() + cnt, b[i]) - a.begin();
    }
    rep(i, 0, n - 1) cout << b[i] << " ";
    cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
