#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    string s;cin >> s;
    if(s == "red") cout << "SSS" << endl;
    else if(s == "blue") cout << "FFF" << endl;
    else if(s == "green") cout << "MMM" << endl;
    else cout << "Unknown" << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}