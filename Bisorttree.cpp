#include <stdio.h>
#include <stdlib.h>

//查找
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */ 
/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode  
{
    int data;
    struct BiTNode *lchild, *rchild; 
} BiTNode, *BiTree;

/* 递归查找二叉排序树T中是否存在key, */
/* 指针f指向T的双亲，其初始调用值为NULL */
/* 若查找成功，则指针p指向该数据元素结点，并返回TRUE */
/* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
Status SearchBTS(BiTree t, int key, BiTree f, BiTree *p){
    if (!t){    /*  查找不成功 */
        *p = f;
        return false;
    }else if(key = t->data){
        *p = t;
        return true;
    }else if(key < t->data){
        return SearchBTS(t->lchild, key, t, p);
    }else{
        return SearchBTS(t->rchild, key, t, p);
    }
}

//插入
struct Bitree {
    int data;
    Bitree *lchild;
    Bitree *rchild;
};
//在二叉排序树中插入查找关键字key
Bitree* InsertBST(Bitree *t, int key){
    if(t == NULL){
        t = new Bitree();
        t->lchild = t->rchild = NULL;
        t->data = key;
        return t;
    }

    if(key<t->data){
        t->lchild = InsertBST(t->lchild,key);
    }else{
        t->rchild = InsertBST(t->rchild, key);
    }
    return t;
}

//n个数据在数组d中，tree为二叉排序树根
Bitree* CreateBitree(Bitree *tree, int d[], int n){
    for(int i=0;i<n;i++){
        tree = InsertBST(tree,d[i]);
    }
}

//删除
/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点, */
/* 并返回TRUE；否则返回FALSE。 */
Status DeleteBST(BiTree *T, int key){
    if(!*T){
        return false;
    }else{
        if(key == (*T)->data)   return Delete(T);   /* 找到关键字等于key的数据元素 */
        else if(key<(*T)->data) return DeleteBST(&(*T)->lchild, key);
        else if(key>(*T)->data) return DeleteBST(&(*T)->rchild, key);
    }
}

/* 从二叉排序树中删除结点p，并重接它的左或右子树。 */
Status Delete(BiTree *p){
    BiTree q,s;
    if ((*p)->lchild == NULL)   /* 右子树空则只需重接它的左子树（待删结点是叶子也走此分支) */
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }else if((*p)->lchild == NULL){ /* 只需重接它的右子树 */
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }else{  /* 左右子树均不空 */
        q = *p;
        s = (*p)->lchild;
        while (s->rchild)   /* 转左，然后向右到尽头（找待删结点的前驱） */
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;   /*  s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值） */
        if(q!=*p){
            q->rchild = s->lchild;  /*  重接q的右子树 */ 
        }else{
            q->lchild = s->lchild;  /*  重接q的左子树 */
        }
        free(s);
    }
    return true;
}
