#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归求深度：深度 = 1 + max(左子树深度, 右子树深度)
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    // 1. 创建各个独立节点
    TreeNode* root = new TreeNode(1);  // 根节点值为1
    TreeNode* node2 = new TreeNode(2); // 节点2
    TreeNode* node3 = new TreeNode(3); // 节点3
    TreeNode* node4 = new TreeNode(4); // 节点4

    // 2. 连接节点形成树结构
    root->left = node2;   // 根节点的左子节点是node2
    root->right = node3;  // 根节点的右子节点是node3
    node2->left = node4;  // node2的左子节点是node4（node2的right仍为nullptr）
    return 0;
}