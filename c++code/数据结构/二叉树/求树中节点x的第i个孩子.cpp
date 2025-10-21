#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x) : val(x) {}
};

// 查找值为 x 的节点（深度优先）
TreeNode* findNode(TreeNode* root, int x) {
    if (root == nullptr) {
        return nullptr;        // 找到底了，没找到
    }
    if (root->val == x) {
        return root;           // 找到了
    }
    for (auto child : root->children) {
        TreeNode* found = findNode(child, x);
        if (found) return found;
    }
    return nullptr;
}

// 获取值为 x 的节点的第 i 个孩子（i 从 1 开始）
TreeNode* getIthChild(TreeNode* root, int x, int i) {
    TreeNode* node = findNode(root, x);
    if (!node || i < 1 || i > (int)node->children.size()) {
        return nullptr;
    }
    return node->children[i - 1]; // 转为0-based索引
}