#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int n;cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, 0, n - 1){
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a));
    ll mex = 0;
    rep(i, 0, n - 1){
        if(mex < a[i].first) break;
        else if(mex >= a[i].first && mex <= a[i].second){
            mex++;
        }
    }
    cout << mex << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}