#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;

const int N = 3e5 + 5;
const ll p = 998244353;

ll power(ll a, ll b) {
    ll res = 1;
    a %= p;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll inv(ll n) {
    return power(n, p - 2);
}

struct Range {
    ll l, r, len;
};

inline void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<Range> a(n);
    rep(i, 0, n - 1) {
        cin >> a[i].l >> a[i].r;
        a[i].len = a[i].r - a[i].l + 1;
    }

    ll ans = n; // E[X] = n - sum(P_equal)
    rep(i, 1, n - 1) {
        ll L = max(a[i-1].l, a[i].l);
        ll R = min(a[i-1].r, a[i].r);
        
        if (L <= R) {
            ll common = R - L + 1;
            // P = common / (len1 * len2)
            ll prob_equal = (common % p) * inv(a[i-1].len % p) % p * inv(a[i].len % p) % p;
            ans = (ans - prob_equal + p) % p;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) T = 1;
    while (T--) solve();
    return 0;
}