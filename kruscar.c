#include <stdio.h>

#define MAXEDGE 100
#define MAXVERTEX   100

typedef struct Edge
{
    int begin;
    int end;
    int weight;
} Edge;

typedef struct Graph
{
    char vertex[MAXVERTEX];
    Edge edges[MAXEDGE];
    int numvertex,numedges;
} MGraph;

void CreateGraph(MGraph *G){
    printf("输入顶点和边数：");
    scanf("%d,%d", &G->numvertex, &G->numedges);
    printf("输入顶点：");
    getchar();
    for (int i = 0; i < G->numvertex; i++)
    {
        scanf("%c", &G->vertex[i]);
    }
    printf("按权值从小到大输入边（vi,vj）对应的起点和终点的下标，begin，end以及权值wight:\n");
    for(int k=0;k<G->numedges;k++){
        Edge e;
        scanf("%d%d%d",&e.begin,e.end,e.weight);
        G->edges[k] = e;
    }
}

int Find(int *parent,int f){
    while (parent[f]>0)
    {
        f = parent[f];
    }
    return f;
}

//最小生成树，克鲁斯卡尔算法
void Kruskal(MGraph *G){
    int parent[MAXVERTEX];
    for(int i=0;i<G->numvertex;i++){
        parent[i] = 0;
    }
    int n,m;
    for(int i=0;i<G->numedges;i++){
        n = Find(parent, G->edges[i].begin);
        m = Find(parent,G->edges[i].end);
        if(n!=m){
            parent[n] = m;
            printf("%d,%d,%d", G->edges[i].begin,G->edges[i].end,G->edges[i].weight);
        }
    }
}

int main(){
    MGraph G;
    CreateGraph(&G);
    Kruskal(&G);

    return 0;
}
