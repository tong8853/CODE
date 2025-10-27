#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int a[22][22];
void solve(){
    int n;cin >> n;
    a[1][1] = 1;
    rep(i, 2, n) rep(j, 1, i){
        a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
    rep(i, 1, n) rep(j, 1, i){
        if(j != i)cout << a[i][j] << " ";
        else cout << a[i][j] << endl; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}