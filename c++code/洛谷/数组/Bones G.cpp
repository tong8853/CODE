#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int ans[100];
void solve(){
    int a, b, c;cin >> a >> b >> c;
    rep(i, 1, a){
        rep(j, 1, b){
            rep(k, 1, c){
                ans[i + j + k]++;
            }
        }
    }
    int pos = 0;
    rep(i, 3, a + b + c){
        if(ans[i] > ans[pos]) pos = i;
    }
    cout << pos << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}