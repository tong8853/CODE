#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int n, k;cin >> n >> k;
    deque<int> dq;
    vi a(n);rep(i, 0, n - 1) cin >> a[i];
    sort(all(a));
    int ans = 0;
    int i = -1;//i到n - 1的时候停止循环
    while(i < n - 1){
        i++;
        ans++;
        dq.push_back(a[i]);
        if(dq.back() - dq.front() > k){
            dq.pop_front();
            ans--;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}