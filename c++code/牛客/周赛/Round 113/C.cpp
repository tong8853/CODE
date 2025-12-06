#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll cnt2 = 0, cnt3 = 0, cnt5 = 0;

void solve(){
    int n; cin >> n;
    rep(i, 1, n){
        int x; cin >> x;
        while(x != 0 && x % 2 == 0){
            cnt2++;
            x /= 2;
        }
        while(x != 0 && x % 3 == 0){
            cnt3++;
            x /= 3;
        }
        while(x != 0 && x % 5 == 0){
            cnt5++;
            x /= 5;
        }
    }
    cout << min({cnt2, cnt3, cnt5}) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}