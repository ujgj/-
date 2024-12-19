#include <iostream>
#include <cmath>
using namespace std;

//数组模拟深度优先
int p[10] = {0};
bool vis[10] = {0};

int n;
void dfs(int x){
    if (x == n+1){
        for(int i=1;i<=n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for (int i=1;i<=n;i++){
        if(vis[i] == false){
            p[x] = i;
            vis[x] = true;
            dfs(x+1);
            vis[i] = false;
        }
    }
}

//实现
int main(){
    while (cin>>n)
    {
        dfs(1);
    }
    return 0;
}
