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
    int l, r;cin >> l >> r;
    int a = 0, b = 0, c = 0;
    int x = r - l + 1;
    int t = x / 3;
    a += t;
    b += t;
    c += t;
    if(x % 3 == 1){
        if(l % 3 == 1){
            a++;
        }else if(l % 3 == 2){
            b++;
        }else c++;
    }else if(x % 3 == 2){
        if(l % 3 == 1){
            a++;
            b++;
        }else if(l % 3 == 2){
            b++;
            c++;
        }else{
            c++;
            a++;
        }
    }
    cout << a << " " << b << " " << c;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}