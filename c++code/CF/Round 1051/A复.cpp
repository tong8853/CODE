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
    vi a(n);
    rep(i, 0,  n - 1){
        cin>> a[i];
    }
    int l = 0, r = n - 1;
    rep(i, 1, n){
        if(a[l] == i){
            l++;
        }else if(a[r] == i){
            r--;
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}