#include <iostream>
using namespace std;

void hanoi(int n, char src, char mid, char dest) {
    if (n == 1) {
        cout << "将盘子1从" << src << "移动到" << dest << endl;
        return;
    }
    hanoi(n - 1, src, dest, mid);
    cout << "将盘子" << n << "从" << src << "移动到" << dest << endl;
    hanoi(n - 1, mid, src, dest);
}

int main() {
    int n;
    cout << "请输入汉诺塔的盘子数量：";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}