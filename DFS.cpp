#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* dfs(Node* root, int target) {
    // 如果当前节点为空，返回空指针
    if (root == nullptr) {
        return nullptr;
    }

    // 如果当前节点的值等于目标值，返回当前节点
    if (root->value == target) {
        return root;
    }

    // 递归地在左子树中查找目标节点
    Node* leftResult = dfs(root->left, target);
    if (leftResult != nullptr) {
        return leftResult;
    }

    // 递归地在右子树中查找目标节点
    Node* rightResult = dfs(root->right, target);
    if (rightResult != nullptr) {
        return rightResult;
    }

    // 如果左右子树都没有找到目标节点，返回空指针
    return nullptr;
}

int main() {
    // 创建二叉树
    Node* root = new Node{ 1, nullptr, nullptr };
    root->left = new Node{ 2, nullptr, nullptr };
    root->right = new Node{ 3, nullptr, nullptr };
    root->left->left = new Node{ 4, nullptr, nullptr };
    root->left->right = new Node{ 5, nullptr, nullptr };

    // 使用DFS算法查找节点值为4的节点
    Node* result = dfs(root, 4);

    // 输出结果
    if (result != nullptr) {
        std::cout << "找到了节点值为4的节点" << std::endl;
    }
    else {
        std::cout << "未找到节点值为4的节点" << std::endl;
    }

    return 0;
}//
// Created by sam on 3/27/24.
//
