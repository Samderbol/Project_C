#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 100

// 定义二叉树结点
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 定义队列
typedef struct {
    TreeNode* data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void InitQueue(Queue* Q) {
    Q->front = Q->rear = 0;
}

// 入队列
void EnQueue(Queue* Q, TreeNode* node) {
    Q->data[Q->rear++] = node;
}

// 出队列
TreeNode* DeQueue(Queue* Q) {
    return Q->data[Q->front++];
}

// 判断队列是否为空
int QueueEmpty(Queue Q) {
    return Q.front == Q.rear;
}

// 创建二叉树结点
TreeNode* CreateTreeNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node) {
        node->data = data;
        node->left = node->right = NULL;
    }
    return node;
}

// 层次遍历二叉树
void BFS(TreeNode* root) {
    if (!root)
        return;

    Queue Q;
    InitQueue(&Q);
    EnQueue(&Q, root);

    while (!QueueEmpty(Q)) {
        TreeNode* node = DeQueue(&Q);
        printf("%c ", node->data);

        if (node->left)
            EnQueue(&Q, node->left);
        if (node->right)
            EnQueue(&Q, node->right);
    }
}
/*
void BFSTraverse(Graph G, Status (*Visit)(int v)) {
    // 按广度优先非递归遍历图 G.使用辅助队列 Q 和访问标志数组 visited。
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = FALSE;
    InitQueue(Q); // 置空的辅助队列

    for (int v = 0; v < G.vexnum; ++v)
        if (!visited[v]) { // v尚未访问
            visited[v] = TRUE;
            Visit(v);
            EnQueue(Q, v); // v入队列
            while (!QueueEmpty(Q)) {
                DeQueue(Q, u); // 队头元素出队并置为u
                for (int w = FirstAdjVex(G, u); w != -1; w = NextAdjVex(G, u, w)) {
                    if (!visited[w]) { // w为u的尚未访问的邻接顶点
                        visited[w] = TRUE;
                        Visit(w);
                        EnQueue(Q, w);
                    }
                }
            }
        }
}
*/
int main() {
    // 创建二叉树
    TreeNode* root = CreateTreeNode('F');
    root->left = CreateTreeNode('A');
    root->right =  nullptr;
    root->left->left = CreateTreeNode('G');
//    root->left->right = CreateTreeNode('B');
//    root->right->left = CreateTreeNode('C');
//    root->right->right = CreateTreeNode('E');

    printf("BFS traversal: ");
    BFS(root);
    printf("\n");

    return 0;
}
