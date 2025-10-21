#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(){
    int n, k;cin >> n >> k;
    vector<int> a(n);
    set<int> s;
    int sum = 0;
    rep(i, 0, n - 1){
        cin >> a[i];
        if(a[i] < k) {
            s.insert(a[i]); // 插入0到k-1的元素
        }else if (a[i] == k) {
            sum++;
        }
    }
    int cnt1 = k - s.size();
    int cnt = max(cnt1, sum);
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}