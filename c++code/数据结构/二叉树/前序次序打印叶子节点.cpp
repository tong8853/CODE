#include <iostream>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 前序遍历打印叶子节点
void preorderPrintLeaves(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // 如果是叶子节点，打印
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->val << " ";
    }

    // 递归遍历左子树和右子树
    preorderPrintLeaves(root->left);
    preorderPrintLeaves(root->right);
}

// 示例：构建一个二叉树并测试
int main() {
    /*
     * 构建如下二叉树：
     *        1
     *       / \
     *      2   3
     *     / \
     *    4   5
     *         \
     *          6
     *
     * 叶子节点是：4, 6, 3
     * 前序遍历顺序访问节点为：1, 2, 4, 5, 6, 3
     * 所以打印叶子节点顺序为：4 6 3
     */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    cout << "前序遍历中的叶子节点: ";
    preorderPrintLeaves(root);
    cout << endl;

    return 0;
}