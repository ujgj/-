#include <iostream>

using namespace std;

void quick_sort(int a[], int low, int high){
    int i, j, temp;
    i = low;
    j = high;
    if(low<high){
        temp = a[low];  //设置枢轴
        while (i!=j)
        {
            while (j>i&&a[j]>=temp)
            {
                --j;
            }
            if(i<j){
                a[i] = a[j];
                ++i;
            }
            while (i<j && a[i]<temp)
            {
                ++i;
            }
            if(i<j){
                a[j] = a[i];
                --j;
            }
        }
        a[i] = temp;
        quick_sort(a, low, i-1);
        quick_sort(a, i+1, high);
    }
}

int main() {
    int a[8]= {70,50,30,20,10,70,40,60};
    int n=8;
    quick_sort(a,0,n-1);
    for(int i=0; i<n; i++) {
        cout<<a[i]<<' ';
    }
    return 0;
}
