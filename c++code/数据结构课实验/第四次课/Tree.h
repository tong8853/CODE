#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 20;

struct TNode {
    char data;
    TNode *f, *rs; // first child, right sibling
    TNode(char c) : data(c), f(nullptr), rs(nullptr) {}
};

class Tree {
public:
    TNode* root;
    Tree() { root = create(); }
    ~Tree() { destroy(root); }
    void pre() { pre(root); cout << endl; }
    void post() { post(root); cout << endl; }
private:
    TNode* create();
    void destroy(TNode* T);
    void pre(TNode* T);
    void post(TNode* T);
};

TNode* Tree::create() {
    char c1, c2;
    TNode *p, *q;
    TNode* Q[MAX] = {nullptr};
    int f = -1, r = -1;

    cout << "输入根节点: ";
    cin >> c1;
    root = new TNode(c1);
    Q[++r] = root;

    cout << "输入节点对(F,C)，以 # # 结束: ";
    while (cin >> c1 >> c2 && !(c1 == '#' && c2 == '#')) {
        p = new TNode(c2);
        Q[++r] = p;
        // Find parent
        for (int i = 0; i <= r; i++) {
            if (Q[i]->data == c1) {
                q = Q[i];
                break;
            }
        }
        if (!q->f) q->f = p;
        else {
            TNode* t = q->f;
            while (t->rs) t = t->rs;
            t->rs = p;
        }
    }
    return root;
}

void Tree::destroy(TNode* T) {
    if (T) {
        destroy(T->f);
        destroy(T->rs);
        delete T;
    }
}

void Tree::pre(TNode* T) {
    if (T) {
        cout << T->data << ' ';
        pre(T->f);
        pre(T->rs);
    }
}

void Tree::post(TNode* T) {
    if (T) {
        post(T->f);
        post(T->rs);
        cout << T->data << ' ';
    }
}

#endif