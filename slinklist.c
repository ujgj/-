#include <stdio.h>
#include <stdlib.h>
//单链表
#define MAXLENGTH      100

//节点结构体
struct Node{
    int data;
    struct Node* next;
};

//创建新节点
struct  Node* Node_create(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode;
};

//首部插入
void insert_head(struct Node** head, int data){
    struct Node* newNode = Node_create(data);
    newNode ->next = *head;
    *head = newNode;
}

//尾部插入
void insert_tail(struct Node* head, int data){
    struct Node* newNode = Node_create(data);
    while (1)
    {
        if (head ->next == NULL){
            head ->next = newNode;
            break;
        }
        head = head ->next;
    }   
}

//中部插入(指定第n个位置)
void insert_between(struct Node* head, int data, int n){
    struct Node* newNode = Node_create(data);
    int length = 1;
    while(head ->next != NULL){
        length += 1;
        head = head ->next;
    }
    int i = 1;
    while(1){
        if (n == 1){
            insert_head(&head, data);
            break;
        }
        else if (n ==length){
            insert_tail(head, data);
            break;
        }
        if (i == n-1){
            struct Node* temp = head ->next ->next;
            head ->next = newNode;
            newNode ->next = temp;
            break;
        }
        head = head ->next;
        i ++;
    }
}

//打印链表
void printlist(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ->",temp ->data);
        temp = temp ->next;
    }
    printf("NULL\n");
}

//运行实现
int main(){
    struct Node* head = NULL;
    insert_head(&head, 1);
    insert_head(&head, 2);
    insert_head(&head, 3);
    insert_tail(head, 4);
    printlist(head);
    return 0 ;
}
