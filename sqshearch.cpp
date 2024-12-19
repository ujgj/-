#include <iostream>

using namespace std;
//遍历思维，一遍for循环
int main(){
    int shangping[6]={10,10,9,10,10,10};
    for(int i=0;i<6;i++){
        if(shangping[i]==9){
            printf("找到次品，他的位置在：%d",i+1);
        }
    }
    return 0;
}
