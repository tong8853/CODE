#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;



void solve(){
    int n;cin >> n;
    vector<vector<int>> a(n + 1);
    int max_len = 0;
    rep(i, 1, n){
        int m;cin >> m;
        if(m > max_len) max_len = m;
        rep(j, 1, m){
            cin >> a[i][j];
        }
    }
    vector<int> ans(max_len + 1);
    int p = 1;//当前扫描的列
    while(p != max_len){
        vector<int> c;//记录候选行的行号
        rep(i, 1, n){//遍历每行
            if(a[i].size() - 1 >= p){
                int min_num = INT_MAX;
                if(a[i][p] < min_num){
                    min_num = a[i][p];
                    c.clear();
                    c.push_back(i);
                }
                if(a[i][p] == min_num) c.push_back(i);
            }
        }
        int cnt = c.size();
        while(cnt > 1){
            p++;
            for(int x : c){
                if(a[x].size() - 1 >= p){
                int min_num = INT_MAX;
                if(a[x][p] < min_num){
                    min_num = a[x][p];
                    c.clear();
                    c.push_back(x);
                }
                if(a[x][p] == min_num) c.push_back(x);
            }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
