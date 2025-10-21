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
    set<pair<int, int>> s;//用set记录所有士兵在的位置
    while(n--){
        int x, y;cin >> x >> y;
        s.insert({x, y});
    }
    int mx = 0;//用于记录可以打到的最大士兵数
    int ansx = 0, ansy = 0;

    /**
     * @brief 
     *  检查坐标(x,y)是否合法（正坐标且不在集合s中）
        计算从(x,y)出发，按照骑士的 8 种走法能到达的已有棋子数量
        如果这个数量大于当前最大值，则更新最大值和最优坐标
     * 
     */

    auto check = [&](int x, int y){
        //把不合法的马的位置给排除掉
        if(x <= 0 || y <= 0){//坐标不能是负的
            return;
        }
        if(s.find({x, y}) != s.end()){//马的位置不能和士兵重合
            return;
        }

        int cnt = 0;//记录当前(x, y)位置能踩到的士兵数
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

    //auto [x, y]c++17引入的结构化语法，可快速获取set里面的pair对的first和second值
    for(auto [x, y] : s){//反向思维，就考虑士兵可能被马踩到的位置，再check这些位置可以踩到的士兵数
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
