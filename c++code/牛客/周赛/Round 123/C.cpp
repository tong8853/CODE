#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

int a[N][4];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;char y;cin>>x>>y;
        a[x][y-'A']=i;
    }
    vector<PII>ans;
    for(auto &x : a){
        int t=0;
        for(auto &y : x){
            if(t&&y)ans.pb({t,y}),t=0;
            else if(!t)t=y;
        }
    }
    cout<< ans.size() * 2 << endl;
    for(auto &[l,r] : ans)cout<< l << " " << r <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}