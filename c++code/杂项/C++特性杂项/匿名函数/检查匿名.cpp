#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

void solve(){
    int n;cin >> n;
    set<pair<int, int>> s;
    while(n--){
        int x, y;cin >> x >> y;
        s.insert({x, y});
    }
    int mx = 0;
    int ansx = 0, ansy = 0;

    /**
     * @brief 
     *  检查坐标(x,y)是否合法（正坐标且不在集合s中）
        计算从(x,y)出发，按照骑士的 8 种走法能到达的已有棋子数量
        如果这个数量大于当前最大值，则更新最大值和最优坐标
     * 
     */

    auto check = [&](int x, int y){
        if(x <= 0 || y <= 0){
            return;
        }
        if(s.find({x, y}) != s.end()){
            return;
        }

        int cnt = 0;
        rep(i, 0, 7){
            int px = x + dx[i], py = y + dy[i];
            if(s.find({px, py}) != s.end()){
                cnt++;
            }
        }

        if(cnt > mx){
            mx = cnt;
            ansx = x;
            ansy = y;
        }
    };
    
    for(auto [x, y] : s){
        rep(i, 0, 7){
            int px = x + dx[i], py = y + dy[i];
            check(px, py);
        }
    }
    cout << ansx << " " << ansy << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;//cin >> T;
	while(T--) solve();
}
