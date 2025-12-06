#ifndef LEAFCOUNT_H
#define LEAFCOUNT_H
#include <iostream>
#include <stack>
using namespace std;

struct BiNode {
    char data;
    BiNode *l, *r;
    BiNode(char c) : data(c), l(nullptr), r(nullptr) {}
};

class LeafCount {
public:
    BiNode* root;
    LeafCount() { root = create(); }
    ~LeafCount() { destroy(root); }
    int count_recur() { int c=0; count_recur(root, c); return c; }
    int count_non_recur();
private:
    BiNode* create();
    void destroy(BiNode* T);
    void count_recur(BiNode* T, int& c);
};

BiNode* LeafCount::create() {
    char c;
    cin >> c;
    if (c == '#') return nullptr;
    BiNode* T = new BiNode(c);
    T->l = create();
    T->r = create();
    return T;
}

void LeafCount::destroy(BiNode* T) {
    if (T) {
        destroy(T->l);
        destroy(T->r);
        delete T;
    }
}

void LeafCount::count_recur(BiNode* T, int& c) {
    if (T) {
        if (!T->l && !T->r) c++;
        count_recur(T->l, c);
        count_recur(T->r, c);
    }
}

int LeafCount::count_non_recur() {
    if (!root) return 0;
    stack<BiNode*> s;
    BiNode* p = root;
    int c = 0;
    while (p || !s.empty()) {
        while (p) {
            s.push(p);
            p = p->l;
        }
        if (!s.empty()) {
            p = s.top(); s.pop();
            if (!p->l && !p->r) c++;
            p = p->r;
        }
    }
    return c;
}

#endif