//
// Created by sam on 24-11-8.
//
#include <iostream>
#include <vector>
#include <algorithm>  // std::max

using namespace std;

// 二叉树结构，数组存储
class BinaryTree {
public:
    vector<int> tree;  // 存储二叉树节点的数组

    // 构造函数，初始化二叉树（假设-1表示空节点）
    BinaryTree(const vector<int>& nodes) : tree(nodes) {}

    // 计算二叉树的深度
    int getDepth(int index = 0) {
        // 如果当前节点为空（-1），返回深度为0
        if (index >= tree.size() || tree[index] == -1) {
            return 0;
        }

        // 计算左子树的深度
        int leftDepth = getDepth(2 * index + 1);
        // 计算右子树的深度
        int rightDepth = getDepth(2 * index + 2);

        // 当前节点的深度是左右子树深度的最大值 + 1
        return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    // 初始化一个二叉树，-1表示空节点
    vector<int> nodes = {10, 5, 15, 1, 8, -1, 20};  // 数组存储的二叉树
    BinaryTree bt(nodes);

    // 输出二叉树的深度
    cout << "The depth of the binary tree is: " << bt.getDepth() << endl;

    return 0;
}
