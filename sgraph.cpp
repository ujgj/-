#include <iostream>
#include <stdio.h>
#include <malloc.h>

#define maxSize 1000
using namespace std;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct
{
    int data;
    ArcNode *firstarc;
} Vnode;

typedef struct{
    Vnode adjlist[maxSize];
    int n, e;
} AGraph;
  
//可以利用结构体整体结构，也可以拆分结构体变为单独搜索
AGraph *graph;

//插入链表末尾
void insertNode(ArcNode *node, ArcNode *newnode){
    ArcNode *p = node;
    while(p->nextarc != NULL){
        p = p->nextarc;
    }
    p->nextarc = newnode;
}

void create(){
    graph = (AGraph*)malloc(sizeof(AGraph));
    cout<<"顶点数："<<endl;
    cin>>graph->n;
    cout<<"边数："<<endl;
    cin>>graph->e;

    int u=-1,v=-1;
    for (int i = 0; i < graph->n; i++)
    {
        graph->adjlist[i].firstarc = NULL;
    }
    
    ArcNode *node;
    for (int i = 0; i < graph->e; i++)
    {
        cout<<"输入联通点A与B"<<endl;
        cin>>u>>v;
        node = (ArcNode*)malloc(sizeof(ArcNode));
        node->adjvex = v;
        node->nextarc = NULL;
        graph->adjlist[u].data = u;
        if (graph->adjlist[u].firstarc == NULL)
        {
            graph->adjlist[u].firstarc = node;
        }else{
            insertNode(graph->adjlist[u].firstarc, node);
        }
    }
}

void travseTree(){
    for (int i = 0; i < graph->n; i++)
    {
        if (graph->adjlist[i].firstarc != NULL)
        {
            cout<<"与"<<i<<"连接的点有：";
            ArcNode *p = graph->adjlist[i].firstarc;
            while (p != NULL)
            {
                cout<<p->adjvex<<" ";
                p = p->nextarc;
            }
            cout<<endl;
        }
    }
}

//DFS
//pos表示当前结点，G表示图，visited[]数组用来表示该节点是否已经访问
void DFS(int pos, AGraph* g, int visited[]){
    ArcNode* p;
    printf("%d", pos);  //打印深度遍历的点
    visited[pos] = 1;   //标记为以访问过
    p = g->adjlist[pos].firstarc;   //将当前点的第一个指针赋值给p

    while (p != NULL)
    {
        //判断该邻接点是否被遍历过
        if(visited[p->adjvex] == 0){
            DFS(p->adjvex, g, visited);
        }
        p = p->nextarc; //后移一位，为之后是否有邻接点做准备
    }
}

//BFS
void BFS(int pos, AGraph* g, int visited[30]){
    int queue[g->n];
    int head=0,tail=0;
    ArcNode *p;
    queue[tail] = pos;
    visited[pos] = 1;
    tail++;
    while (head != tail)
    {
        pos = queue[head];
        head++;
        printf("%d", pos);
        p = g->adjlist[pos].firstarc;
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                queue[tail]=p->adjvex;
                visited[p->adjvex] = 1;
                tail++;
            }
            p = p->nextarc;
        }
    }
}

int main(){
    create();
    travseTree();
    return 0;
}
