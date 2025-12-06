#include "BiTree.h"

int main() {
    cout << "输入扩展前序序列 (如 A B # # C # #): ";
    BiTree T;
    cout << "前序遍历: "; T.pre();
    cout << "中序遍历: "; T.in();
    cout << "后序遍历: "; T.post();
    cout << "层序遍历: "; T.level();
    return 0;
}