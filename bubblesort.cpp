#include <iostream>
//冒泡排序
using namespace std;
void bubble_sort(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]); //交换数据
            }
        }
    }
}

int main(){
    int a[8]= {70,50,30,20,10,70,40,60};
    int n=7;
    bubble_sort(a,n);
    for(int i=0; i<=n; i++) {
        cout<<a[i]<<' ';
    }
    return 0;
}
