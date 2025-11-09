#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

bool isPrime(int x){
    if(x == 1) return false;
    rep(i, 2, sqrt(x)){
        if(x % i == 0) return false;
    }
    return true;
}
void solve(){
    int n;cin >> n;
    int x;
    rep(i, 1, n){
        cin >> x;
        if(isPrime(x)) cout << x << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}