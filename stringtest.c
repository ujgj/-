#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define True        1
#define False       0
//获取字符串长度
int _strlen(char str[]){
    int i = 0;
    for (i=0; str[i] != '\0'; i++){
        return i;
    }
}

//字符位置获取(首次出现)
int _charAt(char str[], char c){
    int i=0;
    for (i=0; str[i]!='\0' && str[i]!=c; i++){
        return i;
    }
}

//拆分字符串(子字符串)
char *_substr(char str[], int i, int j){
    int pos = 0;
    char *backup;
    while(i<j){
        backup[pos++] = str[i++];
    }
    backup[pos] = '\0';
    return backup;;
}

//字符串拆分（前n）
char *_prefix(char str[], int n){
    int pos=0,i;
    char *backup;
    for ( i = 0; i < n; i++)
    {
        backup[pos++] = str[i];
    }
    backup[pos] = '\0';
    return backup;
}

//字符串拆分（后n）
char *_suffix(char str[], int n){
    int len = _strlen(str);

    int pos=0,i;
//    char backup[500];
    char *backup;
    for (i = len-n; i<len; i++){
        backup[pos++] = str[i];
    }
    backup[pos] = '\0';
    return backup;
}

//字符串连接
char *_strcat(char dest[], char src[]){
    char *ret = dest;
    while (*dest != '\0')
    {
        dest ++;
    }
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    return ret;
}

//字符串比较
int _strcmp(char *src, char *dst){
    int ret = 0;
    while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
    {
        ++src, ++dst;
    }
    if (ret < 0) ret = -1;
    else if (ret > 0) ret = 1;
    
    return ret;
}

//暴力匹配法
int isBF(char str1[], char str2[]){
    int flag = False;
    int len1 = _strlen(str1);
    int len2 = _strlen(str2);
    for (int i=0; i<len1; i++){
        for(int j=0; j<len2; j++){
            int pos = i;
            if (str1[pos++] != str2[j]){
                break;
            }else{
                if(j = len2-1)  flag = True;
            }
        }
    }
    return flag;
}

//字符串KMP算法匹配
//创建next表
int *buildNext(char *p){
    int m =strlen(p), j=0;
    int * N = (int *)malloc(m);
    int t = N[0] = -1;
    while (j<m-1)
    {
        if(t<0||p[j] == p[t]){
            N[++j] = ++t;
        }else{
            t = N[t];
        }
    }
    return N;
}
//开始匹配
int KMP(char T[], char P[]){
    int *next = buildNext(P);
    int n = strlen(T), i=0;
    int m =strlen(P), j=0;
    while (j<m && i<n)
    {
        if(j<0||T[i]==P[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    free(next);
    return i-j;
}

//调用
/*
int main(){
    char *str = "hello world !";
    int len = _strlen(str);
    int position = _charAt(str, 'l');
    char *newstr = _substr(str, 1, 5);
    printf("%d, %d, %s", len, position, newstr);
    return 0;
}
*/
int main(){
    char org[] = "ABABABABABD";
    char str[] = "ABABD";
    int ans = KMP(org,str);
    printf("%d", ans);
    return 0;
}
