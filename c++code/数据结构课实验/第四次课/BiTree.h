#ifndef BITREE_H
#define BITREE_H
#include <iostream>
#include <queue>
using namespace std;

struct BiNode {
    char data;
    BiNode *l, *r;
    BiNode(char c) : data(c), l(nullptr), r(nullptr) {}
};

class BiTree {
public:
    BiNode* root;
    BiTree() { root = create(); }
    ~BiTree() { destroy(root); }
    void pre() { pre(root); cout << endl; }
    void in() { in(root); cout << endl; }
    void post() { post(root); cout << endl; }
    void level();
private:
    BiNode* create();
    void destroy(BiNode* T);
    void pre(BiNode* T);
    void in(BiNode* T);
    void post(BiNode* T);
};

BiNode* BiTree::create() {
    char c;
    cin >> c;
    if (c == '#') return nullptr;
    BiNode* T = new BiNode(c);
    T->l = create();
    T->r = create();
    return T;
}

void BiTree::destroy(BiNode* T) {
    if (T) {
        destroy(T->l);
        destroy(T->r);
        delete T;
    }
}

void BiTree::pre(BiNode* T) {
    if (T) {
        cout << T->data << ' ';
        pre(T->l);
        pre(T->r);
    }
}

void BiTree::in(BiNode* T) {
    if (T) {
        in(T->l);
        cout << T->data << ' ';
        in(T->r);
    }
}

void BiTree::post(BiNode* T) {
    if (T) {
        post(T->l);
        post(T->r);
        cout << T->data << ' ';
    }
}

void BiTree::level() {
    if (!root) return;
    queue<BiNode*> q;
    q.push(root);
    while (!q.empty()) {
        BiNode* p = q.front(); q.pop();
        cout << p->data << ' ';
        if (p->l) q.push(p->l);
        if (p->r) q.push(p->r);
    }
    cout << endl;
}

#endif