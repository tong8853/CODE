#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; ++i)
typedef long long ll;

void solve(){
    int n, m;cin >> n >> m;
    vector<string> a(n + 1);
    vector<int> score(n + 1);
    rep(i, 1, n){
        string s;cin >> s;
        a[i] = s;
    }
    rep(i, 1, m){
        int cnt_0 = 0, cnt_1 = 0;
        rep(j, 1, n){
            if(a[j][i - 1] == '0') cnt_0++;
            else cnt_1++;
        }
        //所有人都加，等于不加
        if(cnt_0 < cnt_1){
            rep(j, 1, n){
                if(a[j][i - 1] == '0') score[j]++;
            }
        }
        if(cnt_0 > cnt_1){
            rep(j, 1, n){
                if(a[j][i - 1] == '1') score[j]++;
            }
        }
    }
    int max_score = *max_element(all(score));
    rep(i, 1, n){
        if(score[i] == max_score) cout << i << " ";
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
}
