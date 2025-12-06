#include "ExpTree.h"

int main() {
    char s[100];
    cout << "输入算术表达式 (如 (a+b)*(c+d*e)): ";
    cin >> s;
    ExpTree et(s);
    cout << "前缀表达式 (前序): "; et.pre();
    cout << "中缀表达式 (中序): "; et.in();
    cout << "后缀表达式 (后序): "; et.post();
    return 0;
}