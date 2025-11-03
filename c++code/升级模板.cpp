#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

// 常用类型别名
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using PII = pair<int, int>;

// 循环宏（谨慎使用）
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define fi first
#define se second

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", _print(__VA_ARGS__), cerr << endl
#else
#define debug(...) 0
#endif

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) solve();
}