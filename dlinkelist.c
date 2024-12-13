#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//定义结构体
typedef struct dlinknode
{
    ElemType data;
    struct dlinknode *pre;
    struct dlinknode *next;
} Dlinknode;

typedef Dlinknode* Dlinklist;

//初始化链表
Dlinklist list_init(){
    Dlinklist list = (Dlinklist)malloc(sizeof(Dlinknode));
    list->pre = NULL;
    list->next = NULL;
    list->data = -1;        //-1表示无效数据
    return list;
}

//插入数据
int list_insert(Dlinklist list, int data, int n){
    if (list == NULL || n < 1) return -1;

    Dlinknode* cur = list;
    int i = 0;
    while (cur && i < (n - 1))
    {
        cur = cur->next;
        i ++;
    }
    if (!cur) return -1;

    Dlinknode* new = (Dlinknode*)malloc(sizeof(Dlinknode));
    new->data = data;
    new->pre = cur;
    new->next = cur->next;
    if (cur->next) cur->next->pre = new;
    cur->next = new;
    return 0 ;
}

//删除数据
int list_delete(Dlinklist list, int *data, int n){
    if (list == NULL || data == NULL || n < 1) return -1;

    Dlinknode* cur = list;
    int i = 0;
    while (cur->next && i < (n - 1))
    {
        cur = cur->next;
        i ++;
    }
    if (!cur->next) return -1;

    Dlinknode *delete = cur->next;
    *data = delete->data;
    delete->pre->next = delete->next;
    if (delete->next) delete->next->pre = delete->pre;
    free(delete);   //释放空间资源
    return 0 ;
}

//查找数据
int list_search(Dlinklist list, int *data, int n){
    if (list == NULL || data == NULL || n < 1) return -1;

    Dlinknode* cur = list;
    int i = 0;
    while (cur && i < n)
    {
        cur = cur->next;
        i ++;
    }
    if (!cur) return -1;

    *data = cur->data;
    return 0;
}

//打印链表
void list_print(Dlinklist list){
    Dlinknode* cur = list;
    while (!cur->next)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
}

//销毁链表
void list_destroy(Dlinklist list){
    Dlinknode* cur = list->next;
    Dlinknode* next = NULL;
    while(cur){
        next = cur->next;
        free(cur);
        cur = next;
    }
    list->pre = NULL;
    list->next = NULL;
}

//实现
int main(){
    Dlinklist list = NULL;
    list = list_init();
    list_insert(list, 1, 1);
//    list_print(list);
    return 0;
}
