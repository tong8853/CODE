#include <iostream>
using namespace std;

// 节点结构
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// 约瑟夫环求解函数
void yuesefu(int n, int m) {
    if (n <= 0 || m <= 0) {
        cout << "输入参数错误！" << endl;
        return;
    }

    // 创建循环链表
    Node* head = new Node(1);
    Node* cur = head;
    for (int i = 2; i <= n; ++i) {
        cur->next = new Node(i);
        cur = cur->next;
    }
    cur->next = head;  // 形成环

    // 求解过程
    Node* p = head;
    cout << "出列顺序：";
    while (p->next != p) {  // 只剩一个节点时停止100
        // 移动m-1步
        for (int i = 1; i < m; ++i) {
            p = p->next;
        }
        // 删除下一个节点
        Node* del = p->next;
        cout << del->data << " ";
        p->next = del->next;
        delete del;
    }
    // 剩余节点
    cout << p->data << endl;
    delete p;
}

int main() {
    int n, m;
    cout << "请输入人数n和报数m：";
    cin >> n >> m;
    yuesefu(n, m);
}