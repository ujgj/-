#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length     10      //队列长度

//循环队列
//队列节构设计
typedef struct rqueue
{
    int data[length];
    int rear;
    int front;
} queue;

//初始化
queue *queue_init(){
    queue *q =(queue*)malloc(sizeof(queue));
    if (q == NULL){
        exit(0);    //申请内存失败
    }
    memset(q->data, 0, sizeof(q->data));
    q->front = 0;
    q->rear = 0;
    return q;
}

//入队
void push(queue* q, int data){
    if ((q->rear+1)%length == q->front){
        printf("溢出");
        return;
    }else{
        q->rear = (q->rear+1)%length;
        q->data[q->rear] = data;
    }
}

//出队
void pop(queue *q){
    if (q->rear == q->front){
        printf("队列为空");
        return ;
    }else{
        q->data[q->front] = 0;
        q->front = (q->front+1)%length;
    }
}

//遍历打印
void queue_print(queue *q){
    int i = q->front;
    while(i != q->rear){
        i = (i+1)%length;
        printf("%d ->", q->data[i]);
    }
    printf("\n");
}

//实现
int main(){
    //初始化
    queue* q = queue_init();
    //入队
    printf("入队");
    for (int i=1; i<=6; i++){
        push(q,i);
        queue_print(q);
    }
    //出队
    printf("出队");
    for (int i = 1; i<=6; i++)
    {
        pop(q);
        queue_print(q);
    }
    return 0;
}
