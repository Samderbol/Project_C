#include <cstdio>
#include <cstring>
#define MAX_V 11

typedef struct {              // 图的定义
    int numVertices, numEdges;// 图中实际的顶点数和边数
    char VerticesList[MAX_V]; // 顶点表，MAX_V为已定义常量
    int Edge[MAX_V][MAX_V];   // 邻接矩阵
} MGraph;

int IsExistEL(MGraph G) {
    int degrees[G.numVertices];
    memset(degrees, 0, sizeof(degrees));
    // 遍历无向图统计所有点的度
    for (int i = 0; i < G.numVertices; i++) {
        for (int j = 0; j < G.numVertices; j++) {
            degrees[i] += G.Edge[i][j];
        }
    }
    int count = 0;
    // 遍历degrees数组统计度为奇数的点的个数
    for (int i = 0; i < G.numVertices; i++) {
        if (degrees[i] % 2 != 0) {
            count++;
        }
    }
    // 检查度为奇数的点个数是否为0或者2
    if (count == 0 || count == 2) {
        return 1;// 存在EL路径
    } else {
        return 0;// 不存在EL路径
    }
}

int main() {
    // 以图(a)为例
    MGraph G;
    G.numEdges = 6;
    G.numVertices = 5;
    memset(G.VerticesList, 0, sizeof(G.numVertices));
    char V[5] = {'a', 'b', 'c', 'd', 'e'};
    for (int i = 0; i < G.numVertices; i++) {
        G.VerticesList[i] = V[i];
    }
    memset(G.Edge, 0, sizeof(G.numVertices));
    int M[5][5] = {{0, 1, 0, 0, 1},
                   {1, 0, 1, 1, 0},
                   {0, 1, 0, 1, 0},
                   {0, 1, 1, 0, 1},
                   {1, 0, 0, 1, 0}};
    for (int i = 0; i < G.numVertices; i++) {
        for (int j = 0; j < G.numVertices; j++) {
            G.Edge[i][j] = M[i][j];
        }
    }
    if (IsExistEL(G)) {
        printf("There is a Euler path. ");
    } else {
        printf("There is no Euler path. ");
    }
    return 0;
}