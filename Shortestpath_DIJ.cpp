#include <cstdio>

#define MaxInt 999 // ∞ 用 100 表示

// 定义顶点类型
typedef char VertexType;

// 定义邻接矩阵存储结构
typedef struct {
    VertexType vexs[6]; // 顶点数组，假设有 6 个顶点
    int arcs[6][6];     // 邻接矩阵，存储边的权值
    int vexnum;         // 顶点数
    int arcnum;         // 边数
} MGraph;

void ShortestPath_DIJ(MGraph G, int v0) {
    int i, n, v, min, w;
    n = G.vexnum;
    bool S[n];
    int D[n], Path[n];

    // 辅助数组的初始化
    for (v = 0; v < G.vexnum; ++v) {// 初始化 S[], D[], Path[]
        S[v] = false;
        D[v] = G.arcs[v0][v];
        if (D[v] < MaxInt)// 如果 v0 和 v 之间有弧，则将 v0 作为 v 的前驱
            Path[v] = v0;// 说明 v0 和 v 之间有弧
        else
            Path[v] = -1;
    }
    S[v0] = true;
    D[v0] = 0;

    // 初始化结束，开始迭代计算
    for (i = 1; i < n; i++) {
        min = MaxInt;
        for (w = 0; w < n; w++) {
            if (!S[w] && D[w] < min) {// 选取不在 S 中且具有最小 D 值的顶点 v
                v = w;// v 点是离 v0 最近的顶点
                min = D[w];// min 是当前的最短路径长度
            }
        }
        S[v] = true;// 将离 v0 最近的顶点加入 S
        for (w = 0; w < n; w++) {// 更新从 v0 到其余各顶点的最短路径长度
            if (!S[w] && (D[v] + G.arcs[v][w] < D[w])) {
                D[w] = D[v] + G.arcs[v][w];// 更新最短路径长度
                Path[w] = v;// 记录最短路径
            }
        }
    }

    // 打印结果
    printf("D[]: ");
    for (i = 0; i < n; i++)
        printf("%d ", D[i]);
    printf("\n");
    printf("Path[]: ");
    for (i = 0; i < n; i++)
        printf("%d ", Path[i]);
    printf("\n");
}

int main() {
    // 初始化有向图 G
    MGraph G = {
            {'A', 'B', 'C', 'D', 'E','F'}, // 顶点数组
            {
                    {MaxInt, MaxInt, 10, MaxInt, 30,100}, // 邻接矩阵，表示边的权值
                    {MaxInt, MaxInt, 5, MaxInt, MaxInt,MaxInt},
                    {MaxInt, MaxInt, MaxInt, 50, MaxInt,MaxInt},
                    {MaxInt, MaxInt, MaxInt, MaxInt, MaxInt,10},
                    {MaxInt, MaxInt, MaxInt, 20, MaxInt,60},
                    {MaxInt, MaxInt, MaxInt, MaxInt, MaxInt,MaxInt},
            },
            6, // 顶点数
            8  // 边数
    };

    int v0 = 0; // 假设起始顶点为 A
    ShortestPath_DIJ(G, v0);
    return 0;
}
