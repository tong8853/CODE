#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

struct node{
    int a;
    int b;
    int c;
    int sum;
};
void solve(){
    int n;cin >> n;
    vector<node> q(n);
    rep(i, 0, n - 1){
        cin >> q[i].a >> q[i].b >> q[i].c;
        q[i].sum = q[i].a + q[i].b + q[i].c;
    }
    int cnt = 0;
    rep(i, 1, n - 1){
        rep(j, 0, i - 1){
            if(abs(q[j].a - q[i].a) <= 5 && abs(q[j].b - q[i].b) <= 5 && abs(q[j].c - q[i].c) <= 5 && abs(q[j].sum - q[i].sum) <= 10) cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}