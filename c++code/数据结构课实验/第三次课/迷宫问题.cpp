#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct P {  // 坐标点
    int x, y;
    P(int x=0, int y=0) : x(x), y(y) {}
};

bool solveMaze(vector<vector<int>>& m, P s, P e, vector<P>& p) {
    int r = m.size();
    if (r == 0) return false;
    int c = m[0].size();

    // 方向：上、右、下、左
    int d[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    vector<vector<bool>> v(r, vector<bool>(c, false));  // 访问标记
    stack<P> st;

    st.push(s);
    v[s.x][s.y] = true;

    while (!st.empty()) {
        P cur = st.top();
        st.pop();

        if (cur.x == e.x && cur.y == e.y) {
            p.push_back(cur);
            return true;
        }

        p.push_back(cur);

        // 尝试四个方向
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + d[i][0];
            int ny = cur.y + d[i][1];
            if (nx >= 0 && nx < r && ny >=0 && ny < c && m[nx][ny]==0 && !v[nx][ny]) {
                st.push(P(nx, ny));
                v[nx][ny] = true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> maze = {
        {1,1,1,1,1,1},
        {1,0,0,1,0,1},
        {1,1,0,0,0,1},
        {1,0,0,1,1,1},
        {1,1,0,0,0,1},
        {1,1,1,1,1,1}
    };

    P start(1,1), end(4,4);
    vector<P> path;

    if (solveMaze(maze, start, end, path)) {
        for (auto pt : path) 
            cout << "(" << pt.x << "," << pt.y << ")" << endl;
    } else {
        cout << "无解" << endl;
    }

    return 0;
}