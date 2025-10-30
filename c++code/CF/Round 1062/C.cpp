#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int n;cin >> n;
    int x = 0, y = 0;
    vi a;
    rep(i, 1, n){
        int m;cin >> m;
        a.push_back(m);
        if(m % 2) x++;
        else y++;
    }
    if(x == 0 || y == 0){
        for(auto &x : a) cout << x << " ";
        cout << endl;
    }else{
        sort(all(a));
        for(auto &x : a) cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}