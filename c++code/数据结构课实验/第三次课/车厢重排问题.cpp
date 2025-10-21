#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool rearrange(vector<int>& in, int k) {
    int n = in.size();
    vector<stack<int>> buf(k);  // 缓冲轨
    int t = 1;  // 目标车厢编号

    for (int c : in) {  // c: 当前处理的车厢
        bool ok = false;
        // 找合适的缓冲轨放置
        for (int i = 0; i < k; i++) {
            if (buf[i].empty() || buf[i].top() > c) {
                buf[i].push(c);
                ok = true;
                break;
            }
        }
        if (!ok) return false;  // 无可用轨道

        // 尝试弹出到出轨
        while (true) {
            bool found = false;
            for (int i = 0; i < k; i++) {
                if (!buf[i].empty() && buf[i].top() == t) {
                    buf[i].pop();
                    t++;
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
    }

    // 处理剩余可弹出车厢
    while (t <= n) {
        bool found = false;
        for (int i = 0; i < k; i++) {
            if (!buf[i].empty() && buf[i].top() == t) {
                buf[i].pop();
                t++;
                found = true;
                break;
            }
        }
        if (!found) break;
    }

    return t > n;
}

int main() {
    vector<int> cars = {5,8,1,7,4,2,9,6,3};
    int k = 3;
    cout << (rearrange(cars, k) ? "成功" : "失败") << endl;
    return 0;
}