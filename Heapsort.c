#include <stdio.h>

/* Function: 交换交换根节点和数组末尾元素的值*/
void Swap(int *heap, int len){
    int temp;

    temp = heap[0];
    heap[0] = heap[len-1];
    heap[len-1] = temp;
}

/* Function: 构建大顶堆 */
void BuildMaxHeap(int *heap, int len){
    int i, temp;
    for(i = len/2-1; i>=0;i--){
        if((2*i+1)<len && heap[i]<heap[2*i+1]){ /* 根节点大于左子树 */
            temp = heap[i];
            heap = heap[2*i+1];
            heap[2*i+1] = temp;
            /* 检查交换后的左子树是否满足大顶堆性质 如果不满足 则重新调整子树结构 */
            if((2*(2*i+1))<len && heap[2*i+1]<heap[2*(2*i+1)] || (2*(2*i+1))+2 < len && heap[2*i+1] < heap[2*(2*i+1)+2]){
                BuildMaxHeap(heap, len);
            }
        }
    }
}

int main() {
    int a[8]= {70,50,30,20,10,70,40,60};
    int n=8;
    int i;
  
    for (i = n; i > 0; i--) {
        BuildMaxHeap(a, i);
        Swap(a, i);
    }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
  
    return 0;
}
