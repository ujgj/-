#include <stdio.h>
#include <stdlib.h>

//树的节点
typedef struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
} node;

//树根
typedef struct {
    node* root;
}Tree;

//树的创建
void insert(Tree* tree, int data){
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    //判断树是否为空树
    if(tree->root == NULL){
        tree->root = n;
    }else{
        node* temp = tree->root;
        while (temp != NULL)
        {//二叉排序树
            if(data < temp->data){
                if (temp->left == NULL){
                    temp ->left = n;
                    return;
                }else{
                    temp = temp->left;
                }
            }else{
                if(temp->right == NULL){
                    temp->right = n;
                    return;
                }else{
                    temp = temp->right;
                }
            }
        }
    }
    return;
}

//递归思想
//树的中序遍历 In-order traversal（输出结果为正序排列）
void inorder(node* n){
    if(n != NULL){
        inorder(n->left);
        printf("%d", n->data);
        inorder(n->right);
    }
}

//前序遍历
void frontorder(node* n){
    if (n != NULL){
        printf("%d", n->data);
        frontorder(n->left);
        frontorder(n->right);
    }
}

//后序遍历
void backorder(node* n){
    if(n!=NULL){
        backorder(n->left);
        backorder(n->right);
        printf("%d", n->data);
    }
}

//实现
int main(){
    Tree tree;
    tree.root = NULL;
    int n;
    printf("节点数：");
    scanf("%d", &n);

    //创建树
    for (int i=0;i<n;i++){
        int temp;
        scanf("%d", &temp);
        insert(&tree, temp);
    }
    //遍历输出
    inorder(tree.root);
    return 0;
}
