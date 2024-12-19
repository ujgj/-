#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M   100

//矩阵生成
int i, j, k;
int matrix1[M][M], matrix2[M][M], row1, col1, row2, col2;
void matrix_create(){
    //第一个矩阵
    printf("输入第一个矩阵行和宽：");
    scanf("%d %d", &row1, &col1);
    printf("输入第一个矩阵：");
    for(i=0;i<row1;i++){
        for ( j = 0; j < col1; j++)
        {
            scanf("%d", matrix1[i][j]);
        }
    }

    //第二个矩阵
    printf("输入第二个矩阵行和宽：");
    scanf("%d %d", &row2, &col2);
    printf("输入第二个矩阵：");
    for(i=0;i<row2;i++){
        for ( j = 0; j < col2; j++)
        {
            scanf("%d", matrix2[i][j]);
        }
    }
}
//矩阵乘法
int *matrix_cheng(){
    int ans[M][M];
    memset(ans, 0, sizeof(ans));

    printf("运算结果：");
    for(i=0;i<row1;i++){
        for ( j = 0; j < col2; j++)
        {
            for(k=0;k<col1;k++){
                ans[i][j] = ans[i][j] + matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    for ( i = 0; i < row1; i++)
    {
        for ( j = 0; j < col2; j++)
        {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    return ans;
}

//矩阵加法
int *matrix_jia(int m1[][], int m2[][]){
    int ans[M][M];
    printf("运算结果：");
    for ( i = 0; i < row1; i++)
    {
        for ( j = 0; j < col2; j++)
        {
           ans[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    for (i=0;i<row1;i++){
        for ( j = 0; j < col2; j++)
        {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    return ans;
}

int main(){
    
}
