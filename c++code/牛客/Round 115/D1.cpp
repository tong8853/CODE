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

void solve(){
    int n;cin >> n;
    vector<PII> a(n);
    rep(i, 0, n - 1)cin >> a[i].ff >> a[i].ss;
    sort(all(a));
    priority_queue<int, vi, greater<int>> pq;
    int ans = 0, i = 0;
    while(1){
        //添加左端点 <=ans 的区间 
        while(i < n && a[i].ff <= ans){
            pq.push(a[i].ss);
            i++;
        }
        //清理堆中不符合条件的右端点
        while(pq.size() && pq.top() < ans) pq.pop();
        
        if(pq.size() && pq.top() >= ans){
            ans++;
            pq.pop();
        }else break;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}