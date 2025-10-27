#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int n;cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, 0, n - 1){
        cin >> a[i].first >> a[i].second;
    }

    sort(all(a), [](const auto& x, const auto& y) {
        return x.second < y.second;
    });

    int mex = 0;
    int p = 0;

    for(int x = 0; ; ++x){
        // 找一个右端点 >= x 的区间
        while(p < n && a[p].second < x){
            p++;
        }
        if(p >= n) break;

        // 检查这个区间能否放 x
        if(a[p].first <= x){
            mex = x + 1;
            p++; // 用掉这个区间
        }else break;
    }

    cout << mex << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}