/*******************************************************************************
无向图的邻接表

2016/4/28   yaunwei
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100

typedef char VertexType;    // 顶点类型
typedef int EdgeType;       // 边的权值类型

typedef struct EdgeNode     // 边表结点
{
    int adjvex;
    EdgeType weigth;
    struct EdgeNode *next;  // 链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode   // 顶点表结点
{
    VertexType data;        // 顶点域，存储顶点信息
    EdgeNode *firstedge;    // 边表头指针
}VertexNode;

typedef struct
{
    VertexNode adjList[MAXVEX];
    int numVertexes, numEdges;
}GraphAdjList;

void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);

    for(i = 0; i < G->numVertexes; i++)
    {
        scanf(&G->adjList[i].data);     // 输入顶点信息
        G->adjList[i].firstedge = NULL; // 将边表置为空表
    }

    for(k = 0; k <= G->numEdges; k++)
    {
        printf("输入边(vi, vj)上的顶点序号：\n");
        scanf("%d, %d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); // 向内存申请空间，生成边表结点

        e->adjvex = j;
        // 单链表，VertexNode相当于头结点
        // 头插法
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode)); // 向内存申请空间，生成边表结点
        e->adjvex = i;
        // 头插法
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }

}

int main()
{
    printf("1\n");
    GraphAdjList *G; // 只是一个指针，没有指向的对象，所以下面不能直接传递给函数。
    G->numEdges = 0;
    G->numVertexes = 0;

    CreateALGraph(G);
    return 0;
}
