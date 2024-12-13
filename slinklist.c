#include <stdio.h>
#include <stdlib.h>
//单链表

//定义结构体
typedef struct Node
{
    int data;
    struct Node *next;
} Node, *linklist;

//初始化链表
linklist list_init(){
    Node *L;
    L = (Node*)malloc(sizeof(Node));
    if (L == NULL){
        printf("申请空间失败");
        exit(0);
    }
    L->next = NULL;
}

//头部插入创建
linklist list_chead(){
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;

    int data;
    while (scanf("%d", &data) != EOF)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = data;
        p->next = L->next;
        L->next = p;
    }
    return L;
}


//尾插法创建
linklist list_ctail(){
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    Node *r;
    r = L;
    int data;
    while (scanf("%d", &data) != EOF)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = data;
        r->next = p;
        r = p;
    }
    r->next = NULL;

    return L;
}

//数据插入（指定第n个位置）
linklist list_insert(linklist L, int n, int data){
    Node *pre;
    pre = L;
    int i = 0;
    for (i = 1; i < n; i++){
        pre = pre->next;
    }
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = pre->next;
    pre->next = p;
    return L;
}

//链表指定删除data元素
linklist list_delete(linklist L, int data){
    Node *p,*pre;
    p = L->next;
    
    while (p->data != data)
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;
    free(p);
    return L;
}

//修改链表元素(data->data1)
linklist list_alter(linklist L, int data, int data1){
    Node *p = L->next;
    int i = 0;
    while (p)
    {
        if (p->data == data){
            p->data = data1;
        }
        p = p->next;
    }
    return L;    
}

//打印链表
void list_print(linklist L){
    Node *p = L->next;
    while (p)
    {
        printf("%d ->", p->data);
        p = p->next;
    }
}

//实现
int main(){
    //创建
    linklist list;
    printf("输入数据,EOF为结尾");
    list = list_ctail();
    list_print(list);

    //插入
    int n;
    int data;
    printf("输入位置:");
    scanf("%d", &n);
    printf("输入数据:");
    scanf("%d", &data);
    list_insert(list, n, data);
    list_print(list);

    //修改
    printf("需修改的数据:");
    scanf("%d", &n);
    printf("替换数据:");
    scanf("%d", &data);
    list_alter(list, n, data);
    list_print(list);

    //删除
    printf("需删除的数据:");
    scanf("%d", &data);
    list_delete(list, data);
    list_print(list);

    return 0;
}
