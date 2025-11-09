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

bool isrunyear(int x){
    return (x % 4 == 0 && x % 100 != 0 || x % 400 == 0);
}
void solve(){
    int a, b;cin >> a >> b;
    vi c;
    rep(i, a, b){
        if(isrunyear(i)) c.push_back(i);
    }
    cout << c.size() << endl; //c.size()返回无符号整型，遇到-1可能会下溢出
    rep(i, 0, (int)c.size() - 1) cout << c[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}