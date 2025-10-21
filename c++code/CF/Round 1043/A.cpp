#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    int len1, len2;
    string a, b;cin >> len1 >> a >> len2 >> b;
    deque<char> dp;
    rep(i, 0, len1 - 1){
        dp.push_back(a[i]);
    }
    rep(i, 0, len2 - 1){
        char t;cin >> t;
        if(t == 'D'){
            dp.push_back(b[i]);
        }else{
            dp.push_front(b[i]);
        }
    }
    for(char m : dp){
        cout << m;
    }
    cout << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
