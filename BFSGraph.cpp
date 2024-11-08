//
// Created by sam on 24-10-23.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_VERTEX_NUM 10  // 最大顶点数量

// 图的表示，邻接表法
struct Graph {
    int numVertices;                    // 顶点数量
    vector<vector<int>> adjList;        // 邻接表

    Graph(int V) : numVertices(V), adjList(V) {}

    // 添加边 (u, v)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);        // 添加邻接边
        adjList[v].push_back(u);        // 对于无向图，添加反向边
    }
};

// 模拟访问顶点操作
void visit(int v) {
    cout << "Visited vertex: " << v << endl;
}

// BFS 实现
void BFS(Graph G, int v) {
    bool visited[MAX_VERTEX_NUM] = {false}; // 访问标记数组，初始化为 false
    queue<int> Q;                          // 定义队列用于广度优先搜索

    visit(v);                              // 访问初始顶点 v
    visited[v] = true;                     // 标记 v 为已访问
    Q.push(v);                             // 顶点 v 入队列

    while (!Q.empty()) {                   // 队列不为空时继续循环
        int current = Q.front();           // 取出队首元素
        Q.pop();                           // 出队列
        for (int w : G.adjList[current]) {  // 遍历当前顶点的所有邻接点
            if (!visited[w]) {             // 如果邻接点 w 未被访问
                visit(w);                  // 访问 w
                visited[w] = true;         // 标记 w 为已访问
                Q.push(w);                 // 将 w 入队列
            }
        }
    }
}

int main() {
    // 创建一个有 9 个顶点的图
    Graph G(9);

    // 添加图中的边
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 4);
    G.addEdge(2, 5);
    G.addEdge(2, 6);
    G.addEdge(3, 7);
    G.addEdge(4, 8);

    // 从顶点 0 开始执行广度优先搜索
    BFS(G, 0);

    return 0;
}
