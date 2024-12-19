#include <iostream>

using namespace std;
void shellSort(int arr[], int n){
    int i, j, gap;
    for(gap = n/2; gap>0; gap/=2){
        for(i=0; i<gap; i++){
            for(j=i+gap;i<n;j++){
                for(int k=j;k>0&&arr[k]<arr[k-gap];k-=gap){
                    swap(arr[k-gap], arr[k]);
                }
            }
        }
    }
}

int main() {
    int a[8]= {70,50,30,20,10,70,40,60};
    int n=8;
    shellSort(a,n);
    for(int i=0; i<n; i++) {
        cout<<a[i]<<' ';
    }
    return 0;
}
