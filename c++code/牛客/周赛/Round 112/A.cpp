#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)

void solve(){
    int n, k;cin >> n >> k;
    int a = (n + 10 - 1) / 10;
    int b = 3 * a;
    int c = 6 * a;
    if(k <= a) cout << "Gold Medal" << endl;
    else if(k > a && k <= b) cout << "Silver Medal" << endl;
    else if(k > b && k <= c) cout << "Bronze Medal" << endl;
    else cout << "Da Tie" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}