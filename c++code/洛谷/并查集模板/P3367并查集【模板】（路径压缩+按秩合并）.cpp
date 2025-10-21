#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

const int N = 2e5 + 5;
int pre[N], high[N];

void init(int n){
    rep(i, 1, n){
        pre[i] = i;
        high[i] = 1;
    }
}

int find(int x){
    if(pre[x] == x) return x;
    else return pre[x] = find(pre[x]); 
}

bool unite(int x, int y){//按秩合并， 把x,y所在的树的根节点合并
    x = find(x), y = find(y);
    if(x == y) return false; //两者根节点相同说明不需要合并
    else{
        if(high[x] > high[y]) pre[y] = x;
        else{
            pre[x] = y;
            if(high[x] == high[y]) high[y]++;
        }
        return true;
    }
}

void solve(){
    int n, m;cin >> n >>m;
    init(n);//初始化
    while(m--){//m次操作
        int op, x, y;cin >> op >> x >> y;
        if(op == 1){//按秩合并
            unite(x, y);
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
