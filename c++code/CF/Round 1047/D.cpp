#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve() {
    int n;cin >> n;
    vector<int> b(n + 1);
    map<int, int> cnt;
    rep(i, 1, n) {
        cin >> b[i];
        cnt[b[i]]++;
    }
    // 检查是否存在不满足cnt[x] != x的情况
    for (auto& [x, c] : cnt) {
        if (c != x) {
            cout << -1 << endl;
            return;
        }
    }
    // 构造数组a, 直接把b当成a输出即可
    rep(i, 1, n){
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--) solve();
}
