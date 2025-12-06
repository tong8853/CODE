#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct HTNode {
    char data;
    int w;
    HTNode *l, *r;
    HTNode(char c, int weight) : data(c), w(weight), l(nullptr), r(nullptr) {}
};

struct Compare {
    bool operator()(HTNode* a, HTNode* b) {
        return a->w > b->w;
    }
};

class Huffman {
public:
    HTNode* root;
    map<char, string> code;
    Huffman(const string& text) {
        map<char, int> freq;
        for (char c : text) freq[c]++;
        build_tree(freq);
        build_code(root, "");
    }
    ~Huffman() { destroy(root); }
    string encode(const string& text);
    string decode(const string& bits);
    void print_code() {
        for (auto& p : code) cout << p.first << ": " << p.second << endl;
    }
private:
    void build_tree(map<char, int>& freq);
    void build_code(HTNode* T, string s);
    void destroy(HTNode* T);
};

void Huffman::build_tree(map<char, int>& freq) {
    priority_queue<HTNode*, vector<HTNode*>, Compare> pq;
    for (auto& p : freq) {
        pq.push(new HTNode(p.first, p.second));
    }

    while (pq.size() > 1) {
        HTNode *l = pq.top(); pq.pop();
        HTNode *r = pq.top(); pq.pop();
        HTNode *m = new HTNode('\0', l->w + r->w);
        m->l = l; m->r = r;
        pq.push(m);
    }
    root = pq.top();
}

void Huffman::build_code(HTNode* T, string s) {
    if (!T) return;
    if (T->data != '\0') {
        code[T->data] = s;
        return;
    }
    build_code(T->l, s + "0");
    build_code(T->r, s + "1");
}

string Huffman::encode(const string& text) {
    string res;
    for (char c : text) res += code[c];
    return res;
}

string Huffman::decode(const string& bits) {
    string res;
    HTNode* p = root;
    for (char b : bits) {
        if (b == '0') p = p->l;
        else p = p->r;
        if (!p->l && !p->r) {
            res += p->data;
            p = root;
        }
    }
    return res;
}

void Huffman::destroy(HTNode* T) {
    if (T) {
        destroy(T->l);
        destroy(T->r);
        delete T;
    }
}

#endif