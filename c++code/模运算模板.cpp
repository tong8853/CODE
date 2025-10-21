#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

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

void solve(){
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}

