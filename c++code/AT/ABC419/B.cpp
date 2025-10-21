#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    int q;cin >> q;
    deque<int> a;
    while(q--){
        int type;cin >> type;
        if(type == 1){
            int x;cin >> x;
            if(a.empty()) a.push_front(x);
            else if(x <= a.front()) a.push_front(x);
            else a.push_back(x);
        }else{
            cout << a.front() << endl;
            a.pop_front();
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}
