#include <cstdio>
#include <cstdlib>

#define false 0
#define true 1



// 定义顺序存储二叉树
typedef struct {
    int *SqBiTNode;  // 存储节点的数组
    int ElemNum;     // 树的节点个数
} SqBiTree;

// 判断二叉树是否是二叉搜索树
bool judgeBST(SqBiTree bt) {
    int k, m;
    int *pmin, *pmax;

    // 分配内存，存储每个节点的最小值和最大值
    pmin = (int *)malloc(sizeof(int) * bt.ElemNum);
    pmax = (int *)malloc(sizeof(int) * bt.ElemNum);

    // 初始化辅助数组pmin和pmax
    for (k = 0; k < bt.ElemNum; k++) {
        pmin[k] = pmax[k] = bt.SqBiTNode[k];
    }

    // 从最后一个非叶子节点向根节点遍历
    for (k = bt.ElemNum - 1; k > 0; k--) {
        // 当前节点存在
        if (bt.SqBiTNode[k] != -1) {
            m = (k - 1) / 2;  // 计算父节点索引

            // 如果当前节点是左子节点
            if (k % 2 == 1 && bt.SqBiTNode[k] < pmax[m]) {
                pmin[k] = pmin[m];
            }
                // 如果当前节点是右子节点
            else if (k % 2 == 0 && bt.SqBiTNode[k] > pmin[m]) {
                pmax[k] = pmax[m];
            }
                // 如果不满足BST的条件，返回false
            else {
                free(pmin);
                free(pmax);
                return false;
            }
        }
    }

    // 如果遍历完成没有问题，返回true
    free(pmin);
    free(pmax);
    return true;
}

int main() {
    // 构造一个测试用的顺序存储二叉树
    SqBiTree bt;
    bt.ElemNum = 7;
    bt.SqBiTNode = (int *)malloc(sizeof(int) * bt.ElemNum);

    // 节点值，假设-1表示空节点
    bt.SqBiTNode[0] = 10;  // 根节点
    bt.SqBiTNode[1] = 5;   // 左子节点
    bt.SqBiTNode[2] = 15;  // 右子节点
    bt.SqBiTNode[3] = 1;   // 左子节点的左子节点
    bt.SqBiTNode[4] = 8;   // 左子节点的右子节点
    bt.SqBiTNode[5] = -1;  // 右子节点的左子节点（空）
    bt.SqBiTNode[6] = 20;  // 右子节点的右子节点

    // 判断是否为二叉搜索树
    if (judgeBST(bt)) {
        printf("The tree is a Binary Search Tree.\n");
    } else {
        printf("The tree is not a Binary Search Tree.\n");
    }

    // 释放内存
    free(bt.SqBiTNode);

    return 0;
}
