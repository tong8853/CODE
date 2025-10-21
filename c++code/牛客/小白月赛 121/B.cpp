#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

struct node{
    int a;
    int b;
};

void solve(){
  int n;cin >> n;
  ll t;cin >> t;
  vector<node> a(n);
  ll sum = 0;
  rep(i, 0, n - 1){
    cin >> a[i].a;
    sum += a[i].a;
  } 
  rep(i, 0, n - 1) cin >> a[i].b;
  auto cmp = [&](node x, node y) -> bool{
      return x.a > y.a;
  };
  sort(all(a), cmp);
  ll tar = t - sum;
  ll ans = 0;
  if(tar <= 0){
      cout << 0 << endl;
      return;
  }
  else{
    rep(i, 0, n - 1){
        if (a[i].a == 0) continue;
        ll cnt = (ll)a[i].a * a[i].b;
        if(tar > cnt){
            ans += a[i].b;
            tar -= cnt;
        }else{
            ans += (tar + a[i].a - 1) / a[i].a;
            tar = 0;
            break;
        }
    }
  }
  if(tar > 0) cout << -1 << endl;
  else cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}