#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(){
    int n;cin >> n;
    int cnt1 = 0, cnt2 = 0;
    rep(i, 0, n - 1){
        int x;cin >> x;
        if(x == -1) cnt1++;
        if(x == 0) cnt2++;
    }
    if(cnt1 % 2) cout << cnt2 + 2 << endl;
    else cout << cnt2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}