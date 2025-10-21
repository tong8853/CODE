#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(){
    int n = 0, s = 0, y = 0;
    for(int i=1;i<=12;i++){
		cin >> y;
		n=n + 300 - y;
		if(n < 0){
			cout << "-" << i;
            return;
		} 
		while(n>=100)
		{
			n-=100;
			s+=100;
		}
	}
	cout << s*1.2+n;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
