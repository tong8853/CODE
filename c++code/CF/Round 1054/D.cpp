#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    //匿名函数计算聚集目标字符所需的交换次数
    auto Count = [&](char tar) -> ll {
        vi a;
        rep(i, 0, (int)s.size() - 1) {
            if (s[i] == tar) {
                a.pb(i);
            }
        }
        ll swaps = 0;
        int k = a.size();
        if (k <= 1) return 0;
        int mid = k / 2;
        rep(i, 0, k - 1) {
            swaps += abs(a[i] - (a[mid] - (mid - i))); //往上中位数靠近的算法    
        }
        return swaps;
    };
    
    ll swapA = Count('a');
    ll swapB = Count('b');
    cout << min(swapA, swapB) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}