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

ll F(int a, int m){
    if(a == 0) return 0;
    return 10 * a + min(10000, (10 * (m - 10) * a)) / 10 + F(100 * a / 200, m);
}

void solve(){
    int n;cin >> n;
    double m;cin >> m;// m是一位小数
    int mm = 10 * m;
    cout << F(n, mm) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}