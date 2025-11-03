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
    vector<PII> a(n);rep(i, 0, n - 1) cin >> a[i].ff >> a[i].ss;
    sort(all(a));
    //优先队列存储当前可以为mex加1的区间
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0, mex = 0;
    while(1){
        //添加区间
        while(i < n && a[i].ff <= mex){
            pq.push(a[i].ss);
            i++;
        }
        //清楚当前不符合规范的区间
        while(pq.size() && pq.top() < mex) pq.pop();
        if(pq.size() && pq.top() >= mex){
            mex++;
            pq.pop();
        }else break;
    }
    cout << mex << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}