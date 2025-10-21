#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// 插入节点（保证集合元素唯一）
void insert(Node*& head, int x) {
    Node* cur = head;
    while (cur) {
        if (cur->data == x) return;  // 元素已存在，不插入
        cur = cur->next;
    }
    // 头插法
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
}

// 打印集合
void printSet(Node* head, const string& name) {
    cout << name << "：";
    Node* cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 集合交集
Node* intersection(Node* a, Node* b) {
    Node* res = nullptr;
    unordered_set<int> setB;
    // 先将b中元素存入哈希表
    Node* cur = b;
    while (cur) {
        setB.insert(cur->data);
        cur = cur->next;
    }
    // 查找a中存在于b的元素
    cur = a;
    while (cur) {
        if (setB.count(cur->data)) {
            insert(res, cur->data);
        }
        cur = cur->next;
    }
    return res;
}

// 集合并集
Node* unionSet(Node* a, Node* b) {
    Node* res = nullptr;
    // 先插入a的所有元素
    Node* cur = a;
    while (cur) {
        insert(res, cur->data);
        cur = cur->next;
    }
    // 再插入b的所有元素（自动去重）
    cur = b;
    while (cur) {
        insert(res, cur->data);
        cur = cur->next;
    }
    return res;
}

// 集合差集（a - b）
Node* difference(Node* a, Node* b) {
    Node* res = nullptr;
    unordered_set<int> setB;
    Node* cur = b;
    while (cur) {
        setB.insert(cur->data);
        cur = cur->next;
    }
    // 查找a中不在b的元素
    cur = a;
    while (cur) {
        if (!setB.count(cur->data)) {
            insert(res, cur->data);
        }
        cur = cur->next;
    }
    return res;
}

// 释放链表
void freeList(Node*& head) {
    while (head) {
        Node* del = head;
        head = head->next;
        delete del;
    }
}

int main() {
    Node* a = nullptr;
    Node* b = nullptr;

    // 初始化集合a和b
    int arrA[] = {1, 2, 3, 4, 5};
    int arrB[] = {4, 5, 6, 7, 8};
    for (int x : arrA) insert(a, x);
    for (int x : arrB) insert(b, x);

    printSet(a, "集合A");
    printSet(b, "集合B");

    Node* inter = intersection(a, b);
    printSet(inter, "交集A∩B");

    Node* unin = unionSet(a, b);
    printSet(unin, "并集A∪B");

    Node* diff = difference(a, b);
    printSet(diff, "差集A-B");

    // 释放内存
    freeList(a);
    freeList(b);
    freeList(inter);
    freeList(unin);
    freeList(diff);
}