#include <stdio.h>
#include <stdlib.h>

#define MAXVEX  9
#define INFINITY    65535

typedef struct MGraph
{
    int numVertexes;
    int *vex;
    int arc[MAXVEX][MAXVEX];
} MGraph;

typedef int PathMatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void ShortestPath_Floyd(MGraph *G, PathMatrix *p, ShortPathTable *D){
    int v,w,k;

    for(v=0;v<G->numVertexes;++v){
        for(w=0;w<G->numVertexes;++w){
            (*D)[v][w] = G->arc[v][w];
            (*p)[v][w] = w;
        }
    }
    for(k=0;k<G->numVertexes;++k){
        for(v=0;v<G->numVertexes;++v){
            for(w=0;w<G->numVertexes;++w){
                if((*D)[v][w]>(*D)[v][k]+(*D)[k][w]){
                    (*D)[v][w] = (*D)[v][k]+(*D)[k][w];
                    (*p)[v][w] = (*p)[v][k];
                }
            }
        }
    }
}

void main(){
    MGraph *my_g = (MGraph*)malloc(sizeof(MGraph));
    int i,j;
    int t=0;

    int v0=0;
    int vv=8;

    my_g->numVertexes = MAXVEX;
    my_g->vex = (int *)malloc(sizeof(char)*my_g->numVertexes);
    if(!my_g->vex)  return;
    for(i=0;i<my_g->numVertexes;++i){   //一维数组(图中各结点)初始化{0,1,2,3,4,5,6,7,8}
        my_g->vex[i] = i++;
    }
    for(i=0;i<my_g->numVertexes;++i){
        for(j=0;j<my_g->numVertexes;++j){
            my_g->arc[i][j] = INFINITY;
        }
    }
    // 无向图的权值二维数组为对称矩阵
    my_g->arc[0][1]=1;
    my_g->arc[0][2]=5;
    my_g->arc[1][2]=3;
    my_g->arc[1][3]=7;
    my_g->arc[1][4]=5;
    my_g->arc[2][4]=1;
    my_g->arc[2][5]=7;
    my_g->arc[3][4]=2;
    my_g->arc[3][6]=3;
    my_g->arc[4][5]=3;
    my_g->arc[4][6]=6;
    my_g->arc[4][7]=9;
    my_g->arc[5][7]=5;
    my_g->arc[6][7]=2;
    my_g->arc[6][8]=7;
    my_g->arc[7][8]=4;
    for(i=0;i<my_g->numVertexes;++i){
        for (j=0;i<=i;++j)
        {
            if(i==j){
                my_g->arc[i][j] = 0;
                continue;;
            }
            my_g->arc[i][j] = my_g->arc[j][i];
        }
    }
    for(i=0;i<my_g->numVertexes;++i){
        for(j=0;j<my_g->numVertexes;++j){
            printf("%5d", my_g->arc[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    PathMatrix D;
    ShortPathTable P;
    ShortestPath_Floyd(my_g, &P, &D);
    for(i=0;i<MAXVEX;++i){
        for(j=0;j<MAXVEX;++j){
            printf("%5d", P[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    free(my_g->vex);
}
