#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

void solve(){
    int n, k;cin >> n >> k;
    int sum = 2 * n - k;//sum为距离max_sum的差距
    if(sum % 2){//sum为奇数
        cout << -1 << endl;
        return;
    }else{
        if(n % 2){//n为奇数，sum / 2 = 对角线0个数
            int cnt = 0;//记录当前0的个数
            rep(i, 1, n){
                rep(j, 1, n){
                    if(i == j && cnt < sum / 2){
                        cout << 0;
                        cnt++;
                    }
                    else cout << 1;
                    if(j % n == 0) cout << endl;
                }
            }
        }else{//n为偶数， k / 2 = 对角线0的个数
            int cnt = 0;//记录当前0的个数
            rep(i, 1, n){
                rep(j, 1, n){
                    if(i == j && cnt < k / 2){
                        cout << 0;
                        cnt++;
                    }
                    else cout << 1;
                    if(j % n == 0) cout << endl;
                }
            }
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}
