#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

bool isHui(int x){
    if (x < 10) return true; // 个位数都是回文
    int rev = 0, tmp = x;
    while (tmp > 0) {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return rev == x;
}
void solve(){
    int a, b;cin >> a >> b;
    vi prime;
    vector<bool> notp(b + 1);
    rep(i, 2, b){
        if(!notp[i]) prime.push_back(i);
        for(auto p : prime){
            if(i * p > b) break;
            notp[i * p] = 1;
            if(i % p == 0) break;
        }
    }
    for(auto x : prime){
        if(x >= a && isHui(x)){
            cout << x << endl;
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;//cin >> T;
	while(T--) solve();
}
