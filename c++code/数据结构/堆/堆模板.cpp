#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

//默认是最大优先队列（即优先级最高的元素是最大的元素)
void solve(){
    int n;cin >> n;
    priority_queue<int, vector<int>, greater<int>> a;
    while(n--){
        int op;cin >> op;
        if(op == 1) {
            int x;cin >> x;
            a.push(x);
        }
        if(op == 2) cout << a.top() << endl;
        if(op == 3) a.pop();
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
