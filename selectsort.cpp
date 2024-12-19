#include <iostream>

using namespace std;

void select_sort(int a[], int n){
    int temp;
    for(int i=0;i<n;i++){
        temp = i;
        for(int j=i+1;j<n;j++){
            if(a[temp] > a[j]){
                temp = j;
            }
        }
        swap(a[i],a[temp]);
    }
}

int main(){
    int a[8]={2,10,9,4,8,1,6,5};
    int n=8;
    select_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
