#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int digit;  // 存储一位数字
    Node* next;
    Node(int d) : digit(d), next(nullptr) {}
};

// 从字符串创建链表（逆序存储，如"123"存储为3->2->1）
Node* createList(const string& s) {
    Node* head = nullptr;
    for (char c : s) {
        Node* newNode = new Node(c - '0');
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// 大整数加法
Node* add(Node* a, Node* b) {
    Node* res = nullptr;
    Node* cur = nullptr;
    int carry = 0;  // 进位

    while (a || b || carry) {
        int sum = carry;
        if (a) {
            sum += a->digit;
            a = a->next;
        }
        if (b) {
            sum += b->digit;
            b = b->next;
        }
        carry = sum / 10;
        int digit = sum % 10;

        // 尾插法构建结果链表
        Node* newNode = new Node(digit);
        if (!res) {
            res = newNode;
            cur = res;
        } else {
            cur->next = newNode;
            cur = cur->next;
        }
    }
    return res;
}

// 打印链表（逆序输出，恢复原数字顺序）
void printNumber(Node* head) {
    if (!head) {
        cout << "0";
        return;
    }
    // 先反转链表
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // 打印
    curr = prev;
    while (curr) {
        cout << curr->digit;
        curr = curr->next;
    }
    cout << endl;
    // 恢复原链表（可选，此处为了演示不恢复）
}

// 释放链表
void freeList(Node* head) {
    while (head) {
        Node* del = head;
        head = head->next;
        delete del;
    }
}

int main() {
    string s1, s2;
    cout << "请输入两个大整数：" << endl;
    cin >> s1 >> s2;

    Node* a = createList(s1);
    Node* b = createList(s2);
    Node* sum = add(a, b);

    cout << "和为：";
    printNumber(sum);

    freeList(a);
    freeList(b);
    freeList(sum);
}