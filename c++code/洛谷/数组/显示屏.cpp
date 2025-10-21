#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int b[105];
void solve(){
    int n;cin >> n;
    string b;cin >> b;
    vector<string> d[10] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"},  // 0
        {"..X", "..X", "..X", "..X", "..X"},  // 1
        {"XXX", "..X", "XXX", "X..", "XXX"},  // 2
        {"XXX", "..X", "XXX", "..X", "XXX"},  // 3
        {"X.X", "X.X", "XXX", "..X", "..X"},  // 4
        {"XXX", "X..", "XXX", "..X", "XXX"},  // 5
        {"XXX", "X..", "XXX", "X.X", "XXX"},  // 6
        {"XXX", "..X", "..X", "..X", "..X"},  // 7
        {"XXX", "X.X", "XXX", "X.X", "XXX"},  // 8
        {"XXX", "X.X", "XXX", "..X", "XXX"},  // 9
    };
    rep(i, 0, 4){
        rep(j, 0, n - 1){
            int x = b[j] - '0';
            cout << d[x][i];
            if(j < n - 1) cout << '.';
            else cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}