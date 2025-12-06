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
    int a, b, c, d;cin >> a >> b >> c >> d;
    if(a != c){
        if(a > c) cout << "A" << endl;
        else cout << "B" << endl;
    }else{
        if(b < d) cout << "A" << endl;
        else cout << "B" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}