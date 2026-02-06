#include<bits/stdc++.h>

#define rep(i, l, r) for(ll i = (l); i <= (r); i++)
#define per(i, r, l) for(ll i = (r); i >= (l); i--)

using namespace std;
typedef long long ll;

template <typename T, typename Z>
inline void chkmax(T& x, const Z& y) { x = x > y ? x : y; }

template <typename T, typename Z>
inline void chkmin(T& x, const Z& y) { x = x < y ? x : y; }


bool Mbe;
// #define MULTI
const ll N = 2e5 + 10, M = 1.2e6, mod = 998244353;
ll n, k, m, x, y;


inline void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    // cout << s << endl;
    vector<ll> ans(n + 1);
    ll cur = 0, cnt = 0;
    for (ll i = 0 ; i < s.length(); i++) {
        if (s[i] == '0') cnt++;
        if (s[i] == '1') cnt = 0;
        if (cnt == k) {
            ans[cur++] = i;
            cnt = 0;
        }
    }
    while (cur <= n) {
        ans[cur++] = n;
    }

    for (auto x : ans) cout << x << " " ;
    cout << endl;
}
bool Med;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll q = 1;
#ifdef MULTI
    cin >> q;
#endif
    while (q--) {
        solve();
    }

    // cerr << ((&Med - &Mbe) / 1024.0 / 1024.0) << " Mb" << endl;
    // cerr << (clock() * 1.0 / CLOCKS_PER_SEC ) << " Ms" << endl;
    return 0;
}
