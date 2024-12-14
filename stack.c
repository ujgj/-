#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn    10000

//节点设计
typedef struct stack
{
    int data[maxn];
    int top;
} stack;

//创建栈
stack *stack_init(){
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL){
        printf("分配空间失败");
        exit(0);
    }
    memset(s->data, 0, sizeof(s->data));
    /*
    *memset函数是C和C++语言标准库中用于内存初始化的函数。
    *它接受三个参数：一个指向内存区域的指针、要设置的特定值和要设置的字节数。
    *该函数可以将指定内存区域设置为特定值，常用于对新分配的内存进行初始化，
    *以确保数据的一致性和安全性。
    */
    s->top = 0;
    return s;
}

//入栈（push）
void push(stack *s, int data){
    s->data[s->top] = data;
    s->top ++;
}

//出栈（pop）
void pop(stack *s){
    if (s->top != 0){
        s->data[s->top] = 0;
        s->top --;
    }
}

//打印
void stack_print(stack *s){
    for(int n=s->top-1;n>=0;n--){
        printf("%d\t", s->data[n]);
    }
}

//实现
int main(){
    stack *s = stack_init();
    int data[5] = {11,22,33,44,55};
    for (int i=0;i<5;i++){
        push(s, data[i]);
    }
    stack_print(s);
//元素出栈
    pop(s);
    stack_print(s);
    return 0;
}
