#include <iostream>
using namespace std;

int yuesefu(int n, int m) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
      res = (res + m) % i;
    return res + 1;
}

int main() {
    int n, m;
    cout << "请输入人数n和报数m：";
    cin >> n >> m;
    yuesefu(n, m);
}