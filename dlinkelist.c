#include <stdio.h>
#include <stdlib.h>

//定义结构体
typedef struct line
{
    int data;
    struct line *pre;   //前驱节点
    struct line *next;  //后继节点
}line;

//打印
void line_print(line *head){
    line *list = head;
    while (list)
    {
        printf("%d", list->data);
        list = list->next;
    }   
}

//创建
line * line_init(line * head){
    int num, pos = 1, data;
    head = (line *)malloc(sizeof(line));
    head->pre = NULL;
    head->next = NULL;
    head->data = 0;     //头节点，数据域存贮链表长度（元素个数）

    line* list = head;
    printf("输入数据:");
    while (scanf("%d", &data) != EOF)
    {
        line * node = (line*)malloc(sizeof(line));
        node->pre = NULL;
        node->next = NULL;
        node->data = data;

        list->next = node;
        node->pre = list;
        list = list->next;
        head->data +=1;
    }
    return head;
}

//插入数据(在n出插入data)
line * line_insert(line * head, int data, int n){
    line * temp = (line*)malloc(sizeof(line));
    temp->data = data;
    temp->pre = NULL;
    temp->next = NULL;

//分情况（位置）考虑
    if(n == 1){
        temp->next = head->next;
        temp->pre = head;
        head->next = temp;
        head->data ++;
    }else{
        line * body = head;
        for (int i = 1; i < n-1; i++){
            body = body->next;
        }
        if (body->next == NULL){
            body->next = temp;
            temp->pre = body;
        }else{
            body->next->pre = temp;
            temp->next = body->next;
            body->next = temp;
            temp->pre = body;
        }
    }
    head->data ++;  
}

//删除元素
line * lin_delete(line * head, int data){
    line * list = head;
    while (list)
    {
        if(list->data == data){
            list->pre->next = list->next;
            list->next->pre = list->pre;
            free(list);
            printf("删除成功\n");
            return head;
        }
        list = list->next;
    }
    printf("元素不存在\n");
    return head;
}

//实现
int main(){
    line *head=NULL;
    head = line_init(head);
/*
*插入
*删除
*打印
*/
    return 0 ;
}
