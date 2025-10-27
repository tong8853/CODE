#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int a[10][10];
void solve(){
    int n;cin >> n;
    a[1][1] = 1;
    int now = 2, x = 1, y = 1;
    while(now <= n * n){
        while(y < n && a[x][y + 1] == 0) {//右
            y++;
            a[x][y] = now;
            now++;
        }
        while(x < n && a[x + 1][y] == 0) {//下
            x++;
            a[x][y] = now;
            now++;
        }
        while(y > 1 && a[x][y - 1] == 0){//左
            y--;
            a[x][y] = now;
            now++;
        }
        while(x > 1 && a[x - 1][y] == 0){//上
            x--;
            a[x][y] = now;
            now++;
        }
    }
    rep(i, 1, n){
        rep(j, 1, n){
            if(a[i][j] < 10){
                cout << " " << " " << a[i][j];
            }else cout << " " << a[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}