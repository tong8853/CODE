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
    int cnt;
    int time;
    int i;
};
void solve(){
    int n;cin >> n;
    vector<node> a(n);
    rep(i, 0, n - 1){
        cin >> a[i].cnt >> a[i].time;
        a[i].i = i;
    }
    auto cmp = [&](node a, node b){
        if(a.cnt != b.cnt) return a.cnt > b.cnt; 
        else return a.time < b.time;
    };
    sort(all(a), cmp);
    vi rank(n);
    int cur = 1;
    rank[a[0].i] = cur; //第一名
    rep(i, 1, n - 1){
        if(a[i].cnt != a[i - 1].cnt || a[i].time != a[i - 1].time){
            cur = i + 1;
        }
        rank[a[i].i] = cur;
    }
    rep(i, 0, n - 1){
        cout << rank[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}