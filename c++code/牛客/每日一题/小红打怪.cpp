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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int ans = 0;
    if(y > x){//一直用群体攻击
        while(a > 0 || b > 0){
            a -= y;
            b -= y;
            ans++;
        }
    }else{//一直用单体攻击或者先群体攻击后单体攻击
        int ans1 = 0, ans2 = 0;
        int m = a, n = b;
        while(a > 0 || b > 0){
            if(a > 0){
                a -= x;
                ans1++;
            }
            if(b > 0){
                b -= x;
                ans1++;
            }
        }

        while(m > 0 || n > 0){
            if(m > 0  && n > 0){
                m -= y;
                n -= y;
                ans2++;
            }else if(m > 0){
                m -= x;
                ans2++;
            }else if(n > 0){
                n -= x;
                ans2++;
            }
        }
        ans = min(ans1, ans2);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}