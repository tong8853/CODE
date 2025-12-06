#include "LeafCount.h"

int main() {
    cout << "输入扩展前序序列: ";
    LeafCount lc;
    cout << "递归计数: " << lc.count_recur() << endl;
    cout << "非递归计数: " << lc.count_non_recur() << endl;
    return 0;
}