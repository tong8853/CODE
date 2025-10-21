#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

void solve(){
    int n, k;cin >> n >> k;
    int cnt_1 = 0, cnt_2 = 0;
    rep(i, 1, n){
        int x;cin >> x;
        if(x == 1) cnt_1++;
        else cnt_2++;
    }   
    int sum_max = 2 * (cnt_2 - 1) + 1 * cnt_1;
    int sum_min = (cnt_1 >= cnt_2 - 1 ? n - 1 : 2 * (cnt_2 - 1));
    vector<int> ans;
    if(k < sum_min || k > sum_max){
        cout << -1 << endl;
        return;
    }else{
        rep(i, 1, cnt_2 - (sum_max - k)) ans.push_back(2);
        rep(i, 1, cnt_1 - (sum_max - k)) ans.push_back(1);
        rep(i, 1, sum_max - k){
            ans.push_back(1);
            ans.push_back(2);
        }
    }
    for(auto x : ans){
        cout << x << " ";
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}
