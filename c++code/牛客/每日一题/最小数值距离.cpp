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

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

void solve(){
    int n;cin >> n;
    vector<ll> x;
    ll temp = 1;
    rep(i, 1, 13){
        temp *= i;
        if(i != 2) x.push_back(temp - 1);
    }
    PII ans;
    ll mind = 1e9;
    rep(i, 0, x.size() - 1){
        if(x[i] != 0){
            ll y1 = n / x[i];
            ll y2 = (n + x[i] - 1) / x[i];
            ll d1 = llabs(x[i] * y1 - n);
            ll d2 = llabs(x[i] * y2 - n);
            if(y1 == 2){
                if(d2 < mind){
                    mind = d2;
                    ans = {i + 2, y2};
                }
                continue;
            }
            if(y2 == 2){
                if(d1 < mind){
                mind = d1;
                ans = {i + 2, y1};
                }
                continue;
            }
            
            if(d1 < d2){
                if(d1 < mind){
                    mind = d1;
                    if(i == 0) ans = {i + 1, y1};
                    else ans = {i + 2, y1};
                }
            }else{
                if(d2 < mind){
                    mind = d2;
                    if(i == 0) ans = {i + 1, y2};
                    else ans = {i + 2, y2};
                }
            }
        }else{
            mind = n;
            ans = {1, 1};
        }
    }
    cout << ans.ff << " " << ans.ss;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}