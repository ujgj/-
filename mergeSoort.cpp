#include <iostream>
#include <math.h>

using namespace std;

void merge(int arr[], int l, int mid, int r){
    int aux[r-l+1]; //开辟一个新的数组，将原数组映射进去
    for(int m=1;m<=r;m++){
        aux[m-l] = arr[m];
    }

    int i=l,j=mid+1;//i和j分别指向两个子数组开头部分

    for(int k=l; k<=r; k++){
        if(i>mid){
            arr[k] = aux[j-l];
            j++;
        }else if(j>r){
            arr[k] = aux[i-l];
            i++;
        }else if(aux[i-l]<aux[j-l]){
            arr[k] = aux[i-1];
            i++;
        }else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}

void merge_sort(int arr[], int n){
    for(int sz=1; sz<=n; sz+=sz){
        for(int i=0;i+sz<n;i+=sz){   //i+sz防止越界
            //对局部：arr[i...sz-1]和arr[i+sz.....i+2*sz-1]进行排序
            merge(arr, i, i+sz-1, min(i+sz+sz-1, n-1)); //min函数防止越界
        }
    }
}

int main() {
    int a[8]= {70,50,30,20,10,70,40,60};
    int n=8;
    merge_sort(a,n);
    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}
