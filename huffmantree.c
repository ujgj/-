#include <stdio.h>
#include <stdlib.h>

//哈夫曼树结点结构
typedef struct 
{
    int weight;
    int parent, left,right;
} HTNode,*HuffmanTree;

//构建哈夫曼树
//HT为地址传递的存储哈夫曼树的数组，w为存储结点权重值的数组，n为结点个数
void CreateHuffmanTree(HuffmanTree *HT, int *w, int n){
    if(n<1) return; // 如果只有一个编码就相当于0
    int m =2*n-1;   // 哈夫曼树总节点数，n就是叶子结点
    *HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
    HuffmanTree p = *HT;
    // 初始化哈夫曼树中的所有结点
    for(int i=0;i<=n;i++){
        (p+i)->weight = *(w+i-1);
        (p+i)->parent = 0;
        (p+i)->left = 0;
        (p+i)->right = 0;
    }
    //从树组的下标 n+1 开始初始化哈夫曼树中除叶子结点外的结点
    for(int i=n+1;i<=m;i++){
        (p+i)->weight =0;
        (p+i)->parent = 0;
        (p+i)->left = 0;
        (p+i)->right = 0;
    }
    //构建哈夫曼树
    for(int i=n+1;i<=m;i++){
        int s1,s2;
        Select(*HT, i-1, &s1, &s2);    //查找内容，需要用到查找算法
        (*HT)[s1].parent = (*HT)[s2].parent = i;
        (*HT)[i].left = s1;
        (*HT)[i].right = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}
