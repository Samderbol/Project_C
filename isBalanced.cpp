//
// Created by sam on 24-11-9.
//
#include <iostream>
#include <cmath>  // 用于abs()函数

using namespace std;

// 定义二叉树的节点类
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // 构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        // 判断当前节点的左右子树的高度差是否小于等于1，且左右子树都平衡
        return abs(maxHigh(root->left) - maxHigh(root->right)) <= 1
               && isBalanced(root->left) && isBalanced(root->right);
    }

    // 辅助函数，计算二叉树的高度
    int maxHigh(TreeNode* root) {
        if (root == nullptr)
            return 0;  // 空节点的高度为0

        // 递归计算左右子树的高度，并返回较大值加1
        return max(maxHigh(root->left), maxHigh(root->right)) + 1;
    }
};

int main() {
    // 构建测试树：
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 创建Solution对象并判断是否平衡
    Solution solution;
    bool result = solution.isBalanced(root);

    // 输出结果
    cout << "Is the tree balanced? " << (result ? "Yes" : "No") << endl;

    return 0;
}
