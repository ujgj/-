#include <stdio.h>
#include <stdlib.h>

//顺序队列

#define True    1
#define False   0

//定义节点
typedef struct node
{
    int data;
    struct node *next;
} node;

//队列定义
typedef struct oqueue
{
    node *front;
    node *rear;
} queue;

//初始化节点
node *node_init(){
    node *n = (node*)malloc(sizeof(node));
    if (n == NULL){
        exit(0);
    }
    return n;
}

//初始化队列
queue *queue_init(){
    queue *q = (queue*)malloc(sizeof(queue));
    if(q == NULL){
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//判断队列空
int empty(queue *q){
    if (q->front == NULL){
        return True;   //非空
    }else{
        return False;   //表示空
    }
}

//入队
void push(queue *q, int data){
    node *n = node_init();
    n->data = data;
    n->next = NULL;

    if (empty(q)){
        q->front = n;
        q->rear = n;
    }else{
        q->rear->next = n;      //n成为当前尾结点的下一结点
        q->rear = n;            //让尾指针指向n
    }
}

//出队
void pop(queue *q){
    node *n = q->front;
    if (empty(q)){
        return ;
    }
    if (q->front == q->rear){
        q->front = NULL;
        q->rear == NULL;
        free(n);
    }else{
        q->front = q->front->next;
        free(n);
    }
}

//打印
void queue_print(queue *q){
    node *n = node_init();
    n = q->front;
    if (empty(q)){
        return;
    }
    while (n != NULL)
    {
        printf("%d ->", n->data);
        n = n->next;
    }
    printf("\n");
}

//实现
int main(){
    queue *q = queue_init();
    //入队
    printf("入队\n");
    for (int i=1; i<=5;i++){
        push(q, i);
        queue_print(q);
    }
    //出队
    printf("出队\n");
    for (int i=1;i<=5;i++){
        pop(q);
        queue_print(q);
    }
    return 0;
}
