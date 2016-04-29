/*******************************************************************************
����ͼ���ڽӱ�

2016/4/28   yaunwei
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100

typedef char VertexType;    // ��������
typedef int EdgeType;       // �ߵ�Ȩֵ����

typedef struct EdgeNode     // �߱���
{
    int adjvex;
    EdgeType weigth;
    struct EdgeNode *next;  // ����ָ����һ���ڽӵ�
}EdgeNode;

typedef struct VertexNode   // �������
{
    VertexType data;        // �����򣬴洢������Ϣ
    EdgeNode *firstedge;    // �߱�ͷָ��
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
    printf("���붥�����ͱ���:\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);

    for(i = 0; i < G->numVertexes; i++)
    {
        scanf(&G->adjList[i].data);     // ���붥����Ϣ
        G->adjList[i].firstedge = NULL; // ���߱���Ϊ�ձ�
    }

    for(k = 0; k <= G->numEdges; k++)
    {
        printf("�����(vi, vj)�ϵĶ�����ţ�\n");
        scanf("%d, %d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); // ���ڴ�����ռ䣬���ɱ߱���

        e->adjvex = j;
        // ������VertexNode�൱��ͷ���
        // ͷ�巨
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode)); // ���ڴ�����ռ䣬���ɱ߱���
        e->adjvex = i;
        // ͷ�巨
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }

}

int main()
{
    printf("1\n");
    GraphAdjList *G; // ֻ��һ��ָ�룬û��ָ��Ķ����������治��ֱ�Ӵ��ݸ�������
    G->numEdges = 0;
    G->numVertexes = 0;

    CreateALGraph(G);
    return 0;
}
