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

const int n = 1e6+5;
vi prime;
int a[n]; 
void solve(){
    vi c(n);
    c[1] = 1;//1需要特别处理
    rep(i, 2, n){//用已经获得的质数去筛掉合数
        if(!c[i]) prime.push_back(i);
        for(auto p : prime){
            if(1LL * i * p > n) break;
            c[i * p] = 1;
            if(i % p == 0) break;//防止合数i被筛去多次
        }
    }
    for(auto i : prime) a[i] = 1;
    rep(i, 1, n){
        a[i] += a[i - 1];
    } 

    int q;cin >> q;
    while(q--){
        int l, r;cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}