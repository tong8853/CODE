#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve() {
    int n;cin >> n;
    vector<PII> a(n);
    rep(i, 0, n - 1) {
        cin >> a[i].ff >> a[i].ss;
    }

    sort(all(a)); // 按左端点排序

    bool ok = true;
    rep(i, 0, n - 2) {
        // 检查 a[i] 和 a[i+1] 是否相离
        if (a[i].second < a[i+1].first) { // 相离
            ok = false;
            break;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}