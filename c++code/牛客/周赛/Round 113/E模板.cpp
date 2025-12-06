#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define ff first
#define ss second
typedef long long ll;
const int MAX=0x3f3f3f3f; 
const ll LLMAX=9223372036854775807;
const double PI=acos(-1);
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
constexpr int mod = 1000000007;
ll norm(ll x) {
	x %= mod;
	if (x < 0) x += mod;
    if (x >= mod) x -= mod;
    return x;
}
struct Z;Z power(Z a, ll b);
struct Z {
    ll x; Z(ll x = 0) : x(norm(x)) {}
    ll val() const { return x; }
    Z operator-() const { return Z(norm(mod - x)); }
    Z inv() const { assert(x != 0); return power(*this, mod - 2); }
    Z &operator*=(const Z &rhs) { x = ll(x) * rhs.x % mod; return *this; }
    Z &operator+=(const Z &rhs) { x = norm(x + rhs.x); return *this; }
    Z &operator-=(const Z &rhs) { x = norm(x - rhs.x); return *this; }
    Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
    friend Z operator*(const Z &lhs, const Z &rhs) { Z res = lhs; res *= rhs; return res; }
    friend Z operator+(const Z &lhs, const Z &rhs) { Z res = lhs; res += rhs; return res; }
    friend Z operator-(const Z &lhs, const Z &rhs) { Z res = lhs; res -= rhs; return res; }
    friend Z operator/(const Z &lhs, const Z &rhs) { Z res = lhs; res /= rhs; return res; }
    friend istream &operator>>(istream &is, Z &a) { ll v; is >> v; a = Z(v); return is; }
    friend ostream &operator<<(ostream &os, const Z &a) { return os << a.val(); }
};
Z power(Z a, ll b) {
    Z res = 1;
    for (; b; b /= 2, a *= a) if (b % 2) res *= a;
    return res;
}
const int m=495;
void solve(){
	int n;cin>>n;
	vector<ll>a(n),b(n);
	for(auto &x:a)cin>>x;
	for(auto &x:b)cin>>x;
	vector<vector<Z>>dp(n+1,vector<Z>(m));
    dp[0][0]=1;
    for(auto x:a){
        for(int i=n;i>0;i--){        
            for(int j=0;j<m;j++){
                dp[i][(j+x)%m]+=dp[i-1][j];
            }
        }   
    }
    
    for(auto x:b){
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                dp[i-1][(j+x)%m]+=dp[i][j];
            }
        }   
    }
    for(int j=0;j<m;j++){
        Z sum=0;
        for(int i=0;i<=n;i++)sum+=dp[i][j];
        cout<<sum<<" ";
    }cout<<endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int T=1;
	while(T--){
		solve();
	} 
	return 0;
}