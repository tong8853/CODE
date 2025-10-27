#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int arr[] = {a, b, c};
    sort(arr, arr + 3);
    int x = arr[0], y = arr[1], z = arr[2];
    
    if (x + y <= z) {
        cout << "不是三角形" << endl;
        return;
    }
    
    int x2 = x * x, y2 = y * y, z2 = z * z;
    if (z2 == x2 + y2) {
        cout << "直角三角形" << endl;
    } else if (z2 > x2 + y2) {
        cout << "钝角三角形" << endl;
    } else {
        cout << "锐角三角形" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}