#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define INFINITY    65535
#define MAX_VERTEX_NUM  10

typedef struct MGraph
{
    string vexs[10];
    int arcs[10][10];
    int vexnum,arcnum;
} MGraph;

int LocateVex(MGraph G, string u){
    for(int i=0;i<G.vexnum;i++){
        if(G.vexs[i] == u){
            return i;
        }
    }
    return -1;
}

void CreateDN(MGraph &G){//构造有向网
    string v1,v2;
    int w;
    int i,j,k;
    cout<<"输入顶点和边数: ";
    cin>>G.vexnum>>G.arcnum;

    cout<<"输入顶点：";
    for(i=0;i<G.vexnum;i++){
        cin>>G.vexs[i];
    }

    for(i=0;i<G.vexnum;i++){
        for(j=0;i<G.vexnum;j++){
            G.arcs[i][j] = INFINITY;
        }
    }
    cout<<"输入边和值："<<endl;
    for(k=0;k<G.arcnum;k++){
        cin>>v1>>v2>>w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = w;
    }
}

void ShortestPath_DIJ(MGraph G, int v0, int p[][MAX_VERTEX_NUM], int D[]){
    int v,w,i,j,min;
    bool final[10];

    for(v=0;v<G.vexnum;v++){
        final[v] = false;
        D[v] = G.arcs[v0][v];
        for(w=0;w<G.vexnum;w++){
            p[v][w] = -1;
        }
        if(D[v]<INFINITY){
            p[v][0] = v0;
            p[v][1] = v;
        }
    }
    D[v0] = 0;
    final[v0] = true;

    for(i=1;i<G.vexnum;i++){
        min = INFINITY;
        for(w=0;w<G.vexnum;w++){
            if(!final[w] && min<INFINITY && G.arcs[v][w]<INFINITY &&(min+G.arcs[v][w]<D[w])){
                D[w] = min+G.arcs[v][w];
                for(j=0;j<G.vexnum;j++){
                    p[w][j] = p[v][j];
                    if (p[w][j] == -1)
                    {
                        p[w][j] = w;
                        break;
                    }
                }
            }
        }
    }
}

int main(){
    int i,j;
    MGraph g;
    CreateDN(g);
    int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int D[MAX_VERTEX_NUM];
    ShortestPath_DIJ(g, 0, p , D);

    cout<<"最短路径数组如下"<<endl;
    for(i=0;i<g.vexnum;i++){
        for(j=0;j<g.vexnum;j++){
            cout<<setw(3)<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<g.vexs[0]<<"到各顶点的最短路径及长度为："<<endl;
    for(i=0;i<g.vexnum;i++){
        if(i!=0 && D[i]!=INFINITY){
            cout<<g.vexs[0]<<"_"<<g.vexs[i]<<"的最短路径长度为:"<<D[i];
            cout<<"最短路径为";
            for(j=0;j<g.vexnum;j++){
                if(p[i][j]>-1){
                    cout<<g.vexs[p[i][j]]<<" ";
                }
            }
            cout<<endl;
        }else if(D[i] == INFINITY){
            cout<<g.vexs[0]<<"_"<<g.vexs[i]<<":"<<"不可达"<<endl;
        }
    }
    return 0;
}
