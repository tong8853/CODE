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
    vi a;
    a.push_back(n);
    while(n != 1){
        if(n % 2) n = 3 * n + 1;
        else n /= 2;
        a.push_back(n);
    }
    for(int i = a.size() - 1; i >= 0; i--) cout << a[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}