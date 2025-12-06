#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
int dig = 0;
ll ans = 0;
int find(vll &a, int dig){//找最大和谐度
    int cnt = 0;
    int num = pow(2, dig);
    rep(i, 0, a.size() - 1){
        if(a[i] >= num) cnt++;
        else break;
    }
    if(cnt == n){
        ans++;
    }
}
void solve(){
    cin >> n;
    vll a(2 * n);
    rep(i, 0, 2 * n - 1) cin >> a[i];
    sort(all(a), [](int x, int y) -> bool{
        return x > y;
    });

    rep(i, 0, 50){
        if(a[0] >= pow(2, i)) dig = i;
    }
    int ans = find(a, dig);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}