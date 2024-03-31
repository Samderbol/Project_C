#include <cstdio>
#include <climits>

#define MAX_VERTEX_NUM 100 // 定义顶点数的最大值

typedef char VertexType; // 顶点的数据类型，这里假设为字符型
typedef int VRType;      // 边的权值类型，这里假设为整型

typedef struct {
    VertexType adjvex;
    VRType lowcost;
} CloseEdge[MAX_VERTEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; // 顶点数组
    VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
    int vexnum, arcnum; // 顶点数和边数
} MGraph;

// 查找顶点在图中的位置
int LocateVex(MGraph G, VertexType u) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.vexs[i] == u) {
            return i; // 找到顶点位置
        }
    }
    return -1; // 未找到，返回-1
}

// 寻找 closedge 数组中权值最小的顶点的索引
int minimum(CloseEdge closedge, int n) {
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (closedge[i].lowcost > 0 && closedge[i].lowcost < min) {
            min = closedge[i].lowcost;
            minIndex = i;
        }
    }
    return minIndex;
}

// Prim 算法生成最小生成树
void MiniSpanTree_PRIM(MGraph G, VertexType u) {
    CloseEdge closedge;
    int k, i, j;

    k = LocateVex(G, u); // 找到顶点 u 在 G 中的位置
    for (j = 0; j < G.vexnum; ++j) {
        if (j != k) {
            closedge[j].adjvex = u;
            closedge[j].lowcost = G.arcs[k][j];
        }
    }
    closedge[k].lowcost = 0; // 初始化，U={u}

    for (i = 1; i < G.vexnum; ++i) {
        k = minimum(closedge, G.vexnum); // 选择下一个顶点
        printf("(%c, %c)\n", closedge[k].adjvex, G.vexs[k]); // 输出生成树的边
        closedge[k].lowcost = 0; // 第 k 个点并入 U 集

        for (j = 0; j < G.vexnum; ++j) {
            if (G.arcs[k][j] < closedge[j].lowcost) {
                closedge[j].adjvex = G.vexs[k];
                closedge[j].lowcost = G.arcs[k][j]; // 更新 closedge 数组
            }
        }
    }
}

int main() {
    MGraph G = {
            {'A', 'B', 'C', 'D', 'E','F'}, // 顶点数组
            {
                    {0, 6, 1, 5, INT_MAX,INT_MAX}, // 邻接矩阵
                    {6, 0, 5, INT_MAX, 3, INT_MAX},
                    {1, 5, 0, 5, 6, 4},
                    {5, INT_MAX, 5, 0, INT_MAX, 2},
                    {INT_MAX, 3, 6, INT_MAX, INT_MAX,6},
                    {INT_MAX, INT_MAX, 4, 2, 6,INT_MAX},
            },
            6, // 顶点数
            10  // 边数
    };

    VertexType u = 'A'; // 起始顶点为 A
    MiniSpanTree_PRIM(G, u);

    return 0;
}
