#ifndef EXPTREE_H
#define EXPTREE_H
#include <iostream>
#include <cstring>
using namespace std;

struct ExpNode {
    char data;
    ExpNode *l, *r;
    ExpNode(char c) : data(c), l(nullptr), r(nullptr) {}
};

class ExpTree {
public:
    ExpNode* root;
    ExpTree(const char* s) { root = build(s, 0, strlen(s)-1); }
    ~ExpTree() { destroy(root); }
    void pre() { pre(root); cout << endl; }
    void in() { in(root); cout << endl; }
    void post() { post(root); cout << endl; }
private:
    ExpNode* build(const char* s, int l, int r);
    void destroy(ExpNode* T);
    int find_low_pri(const char* s, int l, int r);
    void pre(ExpNode* T);
    void in(ExpNode* T);
    void post(ExpNode* T);
};

int ExpTree::find_low_pri(const char* s, int l, int r) {
    int pri = 0, min_pri = 3, pos = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(') pri += 2;
        else if (s[i] == ')') pri -= 2;
        else if (s[i] == '+' || s[i] == '-') {
            if (pri + 1 < min_pri) { min_pri = pri + 1; pos = i; }
        }
        else if (s[i] == '*' || s[i] == '/') {
            if (pri + 2 < min_pri) { min_pri = pri + 2; pos = i; }
        }
    }
    return pos;
}

ExpNode* ExpTree::build(const char* s, int l, int r) {
    if (l == r) return new ExpNode(s[l]);
    
    int p = find_low_pri(s, l, r);
    if (p == -1) { // 整个是括号
        if (s[l] == '(' && s[r] == ')')
            return build(s, l+1, r-1);
        else return nullptr; // error
    }

    ExpNode* T = new ExpNode(s[p]);
    T->l = build(s, l, p-1);
    T->r = build(s, p+1, r);
    return T;
}

void ExpTree::destroy(ExpNode* T) {
    if (T) {
        destroy(T->l);
        destroy(T->r);
        delete T;
    }
}

void ExpTree::pre(ExpNode* T) {
    if (T) {
        cout << T->data << ' ';
        pre(T->l);
        pre(T->r);
    }
}

void ExpTree::in(ExpNode* T) {
    if (T) {
        in(T->l);
        cout << T->data << ' ';
        in(T->r);
    }
}

void ExpTree::post(ExpNode* T) {
    if (T) {
        post(T->l);
        post(T->r);
        cout << T->data << ' ';
    }
}

#endif