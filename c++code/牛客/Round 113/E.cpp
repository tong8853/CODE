#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int p = 495;
constexpr int mod = 1000000007;
ll norm(ll x) {
    x %= mod;
    if (x < 0) x += mod;
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
const int m = 495;
void solve(){
    int n;cin >> n;
    vll a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    //dp[i][j],表示从a中取出i个元素，从b中选k个元素（k < i）,且模后总和j的方案数
    vector<vector<Z>> dp(n + 1, vector<Z>(m));
    dp[0][0] = 1;//a取0个数，则b也只能取0个数，模后总和为0
    for(auto &x : a){ //在a中取出x
        for(int i = n; i > 0; i--){ //倒序，因为a里面的数是不可重复取的
            rep(j, 0, m - 1) dp[i][(j + x) % m] += dp[i - 1][j];
        }
    }
    for(auto &x : b){
        rep(i, 1, n) rep(j, 0, m - 1) dp[i - 1][(j + x) % m] += dp[i][j];
    }
    rep(j, 0, m - 1){
        Z sum = 0;
        rep(i, 0, n) sum += dp[i][j];
        cout << sum << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}

