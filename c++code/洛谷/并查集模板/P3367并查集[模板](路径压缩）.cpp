#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

const int N = 2e5 + 5;
int pre[N];

int find(int x){
    if(pre[x] == x) return x;
    else return pre[x] = find(pre[x]); 
}

void solve(){
    int n, m;cin >> n >>m;
    rep(i, 1, n) pre[i] = i; //初始化
    while(m--){
        int op, x, y;cin >> op >> x >> y;
        if(op == 1){//合并
            x = find(x), y = find(y);
            pre[x] = y;
        }else{
            x = find(x), y = find(y);
            if(x == y) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;//cin >> T;
	while(T--) solve();
}
