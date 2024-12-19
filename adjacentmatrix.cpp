#include <iostream>

using namespace std;

const int maxn = 105;
int n,m,x,y;
int adj[maxn][maxn] = {0};

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        adj[x-1][y-1] = 1;
        adj[y-1][x-1] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        for(int j=0; j<m; j++){
            cout<<adj[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
