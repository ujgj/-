#include <stdio.h>
#include <stdlib.h>

int binary_search(int *list, int len, int target){
    int low = 0;
    int height = len - 1;
    int middle;
    while (low <= height)
    {
        middle = (low + height)/2;
        if (list[middle] == target)
        {
            printf("已找到该值，数组下标为:%d\n",middle);
            return list[middle];
        }else if(list[middle] > target){
            height = middle - 1;
        }else if(list[middle] < target){
            low = middle + 1;
        }
    }
    printf("未找到该值");
    return -1;
}

int main(){
    int a[] = {2,4,5,8,9,44};
    int b = binary_search(a,sizeof(a)/4,5);
    printf("b=%d\n",b);

    return 0;
}
