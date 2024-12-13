#include <stdio.h>
#include <stdlib.h>

//循环链表(单链表)
typedef struct list
{
    int data;
    struct list * next;
} list;

//初始化
list *list_init(){
    list *head = (list*)malloc(sizeof(list));
    if (head == NULL){
        printf("创建失败");
        exit(0);
    }else{
        head->next = NULL;
        return head;
    }
}

//创建-插入数据
int list_create(list *head){
    int data;
    printf("插入数据:");
    scanf("%d", &data);

    list *node = list_init();
    node->data = data;

    if (head != NULL){
        list *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = node;
        node->next = head;
        return 1;
    }else{
    printf("头节点无元素");
    return 0;
    }
}

//插入元素
list *list_insert(list *head, int n, int data){
    list *node = list_init();
    list *p = head;
    list *t;
    t = p;
    node->data = data;
    if (head != NULL){
        for (int i=0; i<=n; i++){
            t = t->next;
        }
        node->next = t->next;
        t->next = node;
        return p;
    }
    return p;
}

//删除元素
int list_delete(list *head){
    if (head == NULL){
        printf("空链表");
        return 0;
    }

    list *temp = head;
    list *ptr = head->next;

    int data;
    printf("要删除的元素:");
    scanf("%d", &data);

    while (ptr != NULL)
    {
        if (ptr->data == data){
            if (ptr->next == head){
                temp->next = head;
                free(ptr);
                return 1;
            }
            temp->next = ptr->next;
            free(ptr);
            return 1;
        }
        temp = temp->next;
        ptr = ptr->next;
    }
     printf("元素不存在");
     return 0;
}

//遍历输出
int display(list *head){
    if (head != NULL){
        list *p = head;

        while (p->next != head)
        {
            printf("%d ->", p->data);
            p = p->next;
        }
        return 1;
    }else{
        printf("头节点为空");
        return 0;
    }
}

//实现
int main(){
    //初始化节点
    list *head = list_init();
    head->next = head;
    //插入元素完善链表
    for (int i=0; i<5; i++){
        list_create(head);
    }
    display(head);

    head = list_insert(head, 1, 10);
    display(head);

    return 0;
}
